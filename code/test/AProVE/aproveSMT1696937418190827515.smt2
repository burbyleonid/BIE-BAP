(set-info :smt-lib-version 2.6)
(set-logic QF_NIA)
(set-info :source |AProve team, see http://aprove.informatik.rwth-aachen.de/, submitted for SMT-COMP 2014|)
(set-info :category "industrial")
(set-info :status sat)
(declare-fun b__9 () Int)
(declare-fun a__3 () Int)
(declare-fun a__5 () Int)
(declare-fun a__2 () Int)
(declare-fun a__7 () Int)
(declare-fun a__8 () Int)
(declare-fun a__4 () Int)
(declare-fun a__6 () Int)
(assert (and (>= (+ 1 (* (- 0 1) b__9)) 0) (= (+ (* b__9 a__3) (* (- 0 1) a__3)) 0) (>= (+ (* a__5 a__2) (* (- 0 1) a__2) (* (- 0 1) (* a__5 a__7 a__3))) 0) (>= (+ a__3 (* (- 0 1) (* a__8 a__3))) 0) (>= (+ (* b__9 a__4 a__7) (* (- 0 1) (* b__9 a__6 a__8)) (* (- 0 1) (* b__9 a__4 a__7 a__8))) 0) (>= (+ (* b__9 a__5 a__7) (* (- 0 1) (* b__9 a__7)) (* (- 0 1) (* b__9 a__5 a__7 a__8))) 0) (>= (+ (* b__9 a__8) (* (- 0 1) (* b__9 a__8 a__8))) 0) (>= (+ (* a__4 a__2) (* (- 0 1) (* a__6 a__3)) (* (- 0 1) (* a__4 a__7 a__3))) 0) (not (= (+ (* a__4 a__2) (* (- 0 1) (* a__6 a__3)) (* (- 0 1) (* a__4 a__7 a__3))) 0)) (>= b__9 0) (>= 1 b__9) (>= a__3 0) (>= a__5 0) (>= a__2 0) (>= a__7 0) (>= a__8 0) (>= a__4 0) (>= a__6 0)))
(check-sat)
;;(get-assignment)
;;(get-model)
(exit)
