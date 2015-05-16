;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; Main file o this solution in MIT scheme.
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
(load "other/basic.lisp")
(load "other/list.lisp")
(load "graph/table.lisp")
(load "graph/graph.lisp")
(load "display/display.lisp")

;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; Main program
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
; Example to start program: (program "test.txt")

;;; Start program with gived file.
(define (program filePath)
	(programLoop (read-file filePath) 1))

;;; Program loop which creates cases. It take file (in list) and do solution.
(define programLoop
	(lambda (file numberOfCase)
		(if (null? file)
			#F
			(if (= (car file) 0)
				#T
				(and
					(and
						(testcase (cccdr file) (car file) (caar file) (caaar file) numberOfCase)
						(newline))
					(programLoop (cdrAt file (+ (* (+ (caar file) 1) 3) (* (caaar file) 2))) (+ numberOfCase 1))) ))))

;;; Start new case for test.
(define testcase
	(lambda (file sizeOfGraph numberOfEdges numberOfTests numberOfCase)
		(if (null? file)
			#F
			(and
				(displayCase numberOfCase)
				(findPaths (cdrAt file (* numberOfEdges 3 )) (addEdgesFromFile file (createGraph sizeOfGraph) numberOfEdges) numberOfTests numberOfEdges)
			))))

;;;  Find all paths for number of tests.
(define findPaths
	(lambda (file graph count edgeCount)
		(if (= count 0)
			file
			(and
				(findPaths (ccdr file) graph (- count 1) edgeCount)
				(displayAndFind graph (car file) (caar file) edgeCount)) )))