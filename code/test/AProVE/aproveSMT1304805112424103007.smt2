(set-info :smt-lib-version 2.6)
(set-logic QF_NIA)
(set-info :source |AProve team, see http://aprove.informatik.rwth-aachen.de/, submitted for SMT-COMP 2014|)
(set-info :category "industrial")
(set-info :status sat)
(declare-fun a__5 () Int)
(declare-fun a__2 () Int)
(declare-fun a__3 () Int)
(declare-fun a__4 () Int)
(assert (and (>= (+ (* a__5 a__2) (* (- 0 1) a__2) (* (- 0 1) (* a__5 a__5 a__3))) 0) (>= (+ a__2 (* (- 0 1) a__3)) 0) (>= (+ (* a__5 a__5 a__3) (* (- 0 1) a__2)) 0) (>= (+ (* a__4 a__2) (* (- 0 1) (* a__4 a__3)) (* (- 0 1) (* a__4 a__5 a__3))) 0) (>= (* a__4 a__3) 0) (>= (* a__4 a__5 a__3) 0) (not (and (= (+ (* a__4 a__2) (* (- 0 1) (* a__4 a__3)) (* (- 0 1) (* a__4 a__5 a__3))) 0) (= (* a__4 a__3) 0) (= (* a__4 a__5 a__3) 0))) (>= a__5 0) (>= a__2 0) (>= a__3 0) (>= a__4 0)))
(check-sat)
;;(get-assignment)
;;(get-model)
(exit)
