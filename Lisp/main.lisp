; Čtení ze souboru po řádcích
(define file (open-input-file "test.txt"))
(do ((line (read-line file) (read-line file))) ((eof-object? line))
	;(display line)
	;(newline)
	)

;;===================================== Basics ====================================
(define atom?
	(lambda (x)
		(or (number? x) (symbol? x))))

;;===================================== List ====================================
; Return value from list at passed index.
(define listAt
	(lambda (listL position)
		(if (null? listL)
			'()
			(if (= position 1)
				(car listL)
				(listAt (cdr listL) (- position 1))))))

; Change value at list at index.
(define listChangeValue
	(lambda (listL index value)
		(if (= index 1)
			(cons value (cdr listL))
			(cons (car listL) (listChangeValue (cdr listL) (- index 1) value)))))

(define findMin
	(lambda (listL)
		(mininum listL 9999)))

(define mininum
	(lambda (listL min)
		(if (null? listL)
			min
			(if (> min car listL)
				(mininum (cdr listL) (car listL))
				(mininum (cdr listL) min)))))

;;===================================== Table ====================================
; Return column in table.
(define getColumn
	(lambda (table columnIndex)
		(if (null? table)
			'()
			(cons (listAt (car table) columnIndex) (getColumn (cdr table) columnIndex) ))))

; Return value from table at given index.
(define getValueFromTable
	(lambda (table first second)
		(listAt (listAt table first) second)))

; Flatten n dimension structure to List
(define flatten
	(lambda (s)
		(if (null? s)
			'()
			(if (atom? s)
				(list s)
				(append (flatten (car s)) (flatten (cdr s)))))))

;;===================================== Graph ====================================

;;----------------------------------- Create ----------------------------------
; Create empty list
(define createList
	(lambda (size)
		(if (= size 0) 
			'()
			(cons 0 (createList (- size 1))))))

; Create table of size n X m.
(define createTable
	(lambda (n m)
		(if (= n 0)
			'()
			(cons (createList m) (createTable (- n 1) m)))))

; Create empty graph of size.
(define createGraph 
	(lambda (size)
		(createTable size size)))

; Add directed edge to graph.
(define addDirectedEdge
	(lambda (table start end value)
		(if (= start 1)
			(cons (listChangeValue (car table) end value) (cdr table))
			(cons (car table) (addDirectedEdge (cdr table) (- start 1) end value)))))

; Add biderected edge to graph.
(define addEdge
	(lambda (table start end value)
		(addDirectedEdge (addDirectedEdge table start end value) end start value)))

;;----------------------------------- Neighbours -------------------------------
; Return neighbours from list.
(define neighboursInLine
	(lambda (listL index)
		(if (null? listL)
			'()
			(if (> (car listL) 0)
				(cons index (neighboursInLine (cdr ListL) (+ index 1)))
				(neighboursInLine (cdr listL) (+ index 1)) ))))

; Return neighbours from table.
(define neighbours
	(lambda (table node) 
		(neighboursInLine (listAt table node) 1)))

;;----------------------------------- DFS -------------------------------
(define DFS
	(lambda (graph from to edgeCount)
		(checkDepth graph from to 0 0 edgeCount)))

(define checkDepth
	(lambda (graph u to maxDecibels depth maxDepth)
		(if (> depth maxDepth)
			9999
			(forEachNeighbor graph u to (neighbours graph u) maxDecibels depth maxDepth))))

(define forEachNeighbor
	(lambda (graph u to adjectedNodes maxDecibels depth maxDepth)
		(if (null? adjectedNodes)
			'()
			(cons (getMinimalDecibels graph u (car adjectedNodes) to maxDecibels depth maxDepth)
				  (forEachNeighbor graph u to (cdr adjectedNodes) maxDecibels depth maxDepth)))))

(define getMinimalDecibels
	(lambda (graph u i to maxDecibels depth maxDepth)
		(if (= i to)
			(if (< maxDecibels (getValueFromTable graph u i))
				(getValueFromTable graph u i)
				maxDecibels)
			(nextHopOfDFS graph u i to maxDecibels depth maxDepth))))

(define nextHopOfDFS
	(lambda (graph u i to maxDecibels depth maxDepth)
		(if (< maxDecibels (getValueFromTable graph u i))
			(checkDepth graph i to (getValueFromTable graph u i) (+ depth 1) maxDepth)
			(checkDepth graph i to maxDecibels (+ depth 1) maxDepth)) ))

;;===================================== Test ====================================
(define testGraph
	(addEdge (addEdge (addEdge (addEdge (addEdge (addEdge (addEdge (addEdge (createGraph 7) 1 2 50) 1 3 60) 2 4 120) 3 6 50) 4 6 80) 4 7 70) 5 7 40) 6 7 140))

;(findMin (flatten (DFS testGraph 1 3 9)) )


(flatten testGraph)