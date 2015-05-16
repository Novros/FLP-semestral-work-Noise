;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; File which contains another definitions of display functions.
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
;;;; This file must have loaded file graph.lisp

;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; Display library
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;; Display value or "no path"
(define (displayValueFromFind value)
	(if (= value 999999)
		(display "no path")
		(display value)))

;;; Find minimal tolerance of noise and display it.
(define displayAndFind
	(lambda (graph from to edgeCount)
		(displayValueFromFind (minDFS graph from to edgeCount))
		(newline)))

;;;; Display case number and text with newline.
(define (displayCase numberOfCase)
	(display "Case #")
	(display numberOfCase)
	(newline))