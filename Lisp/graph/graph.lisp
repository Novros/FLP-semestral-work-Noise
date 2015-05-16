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
;;;; This file must have loaded file list.lisp and table.lisp

;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;;;; Table library
;;;;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

;;;;------------------------------------------------ Creating function ------------------------------------------------
;;; Create empty graph of size.
(define (createGraph size)
	(createTable size size))

;;; Add unidirected edge to graph.
(define (addDirectedEdge table start end value)
	(if (= start 1)
		(cons
			(listChangeValue (car table) end value)
			(cdr table))
		(cons
			(car table)
			(addDirectedEdge (cdr table) (- start 1) end value))))

;;; Add biderected edge to graph.
(define (addEdge table start end value)
	(addDirectedEdge (addDirectedEdge table start end value) end start value))

;;;;------------------------------------------------ Neighbours function ------------------------------------------------
;;; Return neighbours from list.
(define neighboursInLine
	(lambda (listL index)
		(if (null? listL)
			'()
			(if (> (car listL) 0)
				(cons
					index
					(neighboursInLine (cdr ListL) (+ index 1)))
				(neighboursInLine (cdr listL) (+ index 1)) ))))

;;; Return neighbours from table.
(define (neighbours table node) 
	(neighboursInLine (listAt table node) 1))

;;;;------------------------------------------------ DFS function ------------------------------------------------
;;; Find minimal value of decibels from all routes to destination.
(define (minDFS graph from to edgeCount)
	(findMin (flatten (DFS graph from to edgeCount))))

;;; Find all routes to destination, but return only max decibels by route.
(define (DFS graph from to edgeCount)
	(checkDepth graph from to 0 0 edgeCount))

;;; Chechk if depth of DFS is not too deep.
(define (checkDepth graph u to maxDecibels depth maxDepth)
	(if (> depth maxDepth)
		999999 ; Return infinity.
		(forEachNeighbor graph u to (neighbours graph u) maxDecibels depth maxDepth)))

;;; For each neighbor of node u do DFS. 
(define forEachNeighbor
	(lambda (graph u to adjectedNodes maxDecibels depth maxDepth)
		(if (null? adjectedNodes)
			999999
			(cons (getMinimalDecibels graph u (car adjectedNodes) to maxDecibels depth maxDepth)
				  (forEachNeighbor graph u to (cdr adjectedNodes) maxDecibels depth maxDepth)))))

;;; Check if we are in destination.
(define getMinimalDecibels
	(lambda (graph u i to maxDecibels depth maxDepth)
		(if (= i to)
			(if (< maxDecibels (getValueFromTable graph u i))
				(getValueFromTable graph u i)
				maxDecibels)
			; Go to next edge and set new maximum of decibels or stay old.
			(if (< maxDecibels (getValueFromTable graph u i))
				(checkDepth graph i to (getValueFromTable graph u i) (+ depth 1) maxDepth)
				(checkDepth graph i to maxDecibels (+ depth 1) maxDepth)))))

;;;;------------------------------------------------ File function ------------------------------------------------
;;; Add edges from file to graph.
(define (addEdgesFromFile file graph count)
	(if (= count 0)
		graph
		(addEdgesFromFile (cccdr file) (addEdge graph (car file) (caar file) (caaar file)) (- count 1))))