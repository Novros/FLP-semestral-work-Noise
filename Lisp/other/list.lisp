;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; File with some list operations.
;;;;
;;;; author  Rostislav Novak <rostislav.novak92@gmail.com>
;;;; version 1.0
;;;;
;;;; This program is free software; you can redistribute it and/or
;;;; modify it under the terms of the GNU General Public License as
;;;; published by the Free Software Foundation; either version 2 of
;;;; the License, or (at your option) any later version.
;;;;
;;;; This program is distributed in the hope that it will be useful, but
;;;; WITHOUT ANY WARRANTY; without even the implied warranty of
;;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
;;;; General Public License for more details at
;;;; http://www.gnu.org/copyleft/gpl.html
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; List file
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;;------------------------------------------------ Creating function ------------------------------------------------
;;; Create empty list of size n
(define (createList size)
	(if (= size 0) 
		'()
		(cons
			0
			(createList (- size 1)))))

;;;;------------------------------------------------ Reading function -------------------------------------------------
;;; Returns second element of list.
(define (caar list)
	(car
		(cdr list)))

;;;  Returns third element of list
(define (caaar list)
	(caar
		(cdr list)))
;;; Return list without first two elements.
(define (ccdr list)
	(cdr
		(cdr list)))

;;; Returns list without first three elements.
(define (cccdr list)
	(cdr
		(ccdr list)))

;;; Returns list without first n elements.
(define (cdrAt list n)
	(if (= n 1)
		(cdr list)
		(cdrAt (cdr list) (- n 1))))

;;; Return value from list at index
(define (listAt list index)
	(if (null? list)
		'()
		(if (= index 1)
			(car list)
			(listAt (cdr list) (- index 1)))))

;;;;------------------------------------------------ Changing function ------------------------------------------------
;;; Change value of element at index.
(define listChangeValue
	(lambda (list index value)
		(if (= index 1)
			(cons
				value
				(cdr list))
			(cons
				(car list)
				(listChangeValue (cdr list) (- index 1) value)))))

;;;;------------------------------------------------ Searching function -----------------------------------------------
;;; Find minimun in list.
(define (findMin list)
	(if (null? list)
		'()
		(mininum (cdr list) (car list))))

;;; Helper function for finding minimum.
(define mininum
	(lambda (list min)
		(if (null? list)
			min
			(if (> min (car list))
				(mininum (cdr list) (car list))
				(mininum (cdr list) min)))))