; Čtení ze souboru po řádcích
(define file (open-input-file "test.txt"))
(do ((line (read-line file) (read-line file))) ((eof-object? line))
	;(display line)
	;(newline)
	)
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
(define forEachNeighbor
	(lambda (graph u to adjectedNodes maxDecibels)
		(if (null? adjectedNodes)
			'()
			(cons (getMinimalDec graph u (car adjectedNodes) to maxDecibels) (forEachNeighbor graph u to (cdr adjectedNodes) maxDecibels)))))

(define getMinimalDec
	(lambda (graph u i to maxDecibels)
		(if (= i to)
			(if (< maxDecibels (getValueFromTable graph u i))
				(getValueFromTable graph u i)
				(maxDecibels))
			(nextHop graph u i to maxDecibels))))

(define nextHop
	(lambda (graph u i to maxDecibels)
		(if (< maxDecibels (getValueFromTable graph u i))
			(forEachNeighbor graph i to (neighbours graph i) (getValueFromTable graph u i))
			(forEachNeighbor graph i to (neighbours graph i) maxDecibels))))

;;===================================== Test ====================================
(define testGraph
	(addEdge (addEdge (addEdge (addEdge (addEdge (addEdge (createGraph 7) 1 2 50) 1 3 60) 2 4 120) 3 6 50) 4 6 80) 5 7 40)
	)

(forEachNeighbor testGraph 7 5 (neighbours testGraph 7) 0)
