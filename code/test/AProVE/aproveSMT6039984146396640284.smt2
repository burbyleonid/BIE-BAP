(set-info :smt-lib-version 2.6)
(set-logic QF_NIA)
(set-info :source |AProve team, see http://aprove.informatik.rwth-aachen.de/, submitted for SMT-COMP 2014|)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun b__10 () Int)
(declare-fun a__2 () Int)
(declare-fun a__8 () Int)
(declare-fun a__9 () Int)
(declare-fun a__5 () Int)
(declare-fun a__7 () Int)
(declare-fun a__3 () Int)
(assert (and (>= (+ 1 (* (- 0 1) b__10)) 0) (= (+ (* b__10 a__2) (* (- 0 1) a__2)) 0) (>= (+ (* b__10 a__8) (* (- 0 1) b__10)) 0) (>= (+ (* b__10 a__9) (* (- 0 1) b__10)) 0) (>= (+ (* a__5 a__2) (* (- 0 1) (* a__7 a__2)) (- 0 1)) 0) (= (* a__8 a__2) 0) (= (* a__9 a__2) 0) (= a__3 0) (>= b__10 0) (>= 1 b__10) (>= a__2 0) (>= a__8 0) (>= a__9 0) (>= a__5 0) (>= a__7 0) (>= a__3 0)))
(check-sat)
;;(get-assignment)
;;(get-model)
(exit)
