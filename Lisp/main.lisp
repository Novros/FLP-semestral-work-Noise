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
			(if (eq? position 0)
				(car listL)
				(listAt (cdr listL) (- position 1))))))

; Change value at list at index.
(define listChangeValue
	(lambda (listL index value)
		(if (= index 0)
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

; Add edge to graph.
(define addEdge
	(lambda (table start end value)
		(if (= start 0)
			(cons (listChangeValue (car table) end value) (cdr table))
			(cons (car table) (addEdge (cdr table) (- start 1) end value)))))

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
		(neighboursInLine (listAt table node) 0)))


;;===================================== Test ====================================
(neighbours '((0 88 0 32) (0 0 0 70) (0 1 0 0) (3 0 0 0)) 0)

(addEdge (createGraph 5) 1 2 5)
