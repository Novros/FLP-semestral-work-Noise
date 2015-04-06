; Čtení ze souboru po řádcích
(define file (open-input-file "test.txt"))
(do ((line (read-line file) (read-line file))) ((eof-object? line))
	;(display line)
	;(newline)
	)

(define listAt
	(lambda (listL position)
		(cond
			((null? listL) '())
			((null? position) '())
			((= position 0) car listL)
			(else listAt (cdr listL) (- position 1)))))

(define getValueFromTable
	(lambda (table first second)
		(listAt (listAt table first) second)))


(getValueFromTable '((1 0 0) (0 1 0) (0 0 1)) 3 1 )