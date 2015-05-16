;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; File which contains function over table.
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
;;;; Headers
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; This file must have loaded file list.lisp

;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; Table library
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;;------------------------------------------------ Creating function ------------------------------------------------
;;; Create table of size n X m.
(define (createTable n m)
	(if (= n 0)
		'()
		(cons
			(createList m)
			(createTable (- n 1) m))))

;;; Flatten n dimension structure to List
(define (flatten s)
	(if (null? s)
		'()
		(if (atom? s)
			(list s)
			(append (flatten (car s)) (flatten (cdr s))))))

;;;;------------------------------------------------ Reading function ------------------------------------------------
;;; Return column in table.
(define (getColumn table columnIndex)
	(if (null? table)
		'()
		(cons
			(listAt (car table) columnIndex)
			(getColumn (cdr table) columnIndex) )))

;;; Return value from table at given index.
(define getValueFromTable
	(lambda (table first second)
		(listAt (listAt table first) second)))