(set-info :smt-lib-version 2.6)
(set-logic QF_NIA)
(set-info :source |AProve team, see http://aprove.informatik.rwth-aachen.de/, submitted for SMT-COMP 2014|)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun b__16 () Int)
(declare-fun a__6 () Int)
(declare-fun b__17 () Int)
(declare-fun a__2 () Int)
(declare-fun a__3 () Int)
(declare-fun a__8 () Int)
(declare-fun a__10 () Int)
(declare-fun a__7 () Int)
(declare-fun a__11 () Int)
(declare-fun a__14 () Int)
(declare-fun a__9 () Int)
(declare-fun a__15 () Int)
(declare-fun a__12 () Int)
(declare-fun a__4 () Int)
(declare-fun a__1 () Int)
(declare-fun a__5 () Int)
(assert (and (>= (+ 1 (* (- 0 1) b__16)) 0) (= (+ (* b__16 a__6) (* (- 0 1) a__6)) 0) (>= (+ 1 (* (- 0 1) b__17)) 0) (= (+ (* b__17 a__2) (* (- 0 1) a__2)) 0) (>= (+ a__3 (* (- 0 1) (* a__8 a__6))) 0) (>= (+ a__6 (* (- 0 1) (* a__10 a__2)) (* (- 0 1) a__3)) 0) (>= (+ (* b__16 a__7) (* b__16 a__11 a__8) (* (- 0 1) (* b__16 a__11))) 0) (>= (+ (* b__16 a__14 a__8) (* (- 0 1) b__16)) 0) (>= (+ (* b__17 a__9) (* b__17 a__11 a__10) (* (- 0 1) (* b__17 a__15))) 0) (>= (+ (* b__17 a__9) (* b__17 a__12 a__10) (* (- 0 1) (* b__17 a__4))) 0) (>= (+ a__1 (* a__4 a__2) (* (- 0 1) a__5) (* (- 0 1) (* a__7 a__6))) 0) (>= (+ a__5 (* (- 0 1) a__1) (* (- 0 1) (* a__9 a__2))) 0) (not (and (= (+ a__1 (* a__4 a__2) (* (- 0 1) a__5) (* (- 0 1) (* a__7 a__6))) 0) (= (+ a__5 (* (- 0 1) a__1) (* (- 0 1) (* a__9 a__2))) 0))) (>= b__16 0) (>= 1 b__16) (>= a__6 0) (>= b__17 0) (>= 1 b__17) (>= a__2 0) (>= a__3 0) (>= a__8 0) (>= a__10 0) (>= a__7 0) (>= a__11 0) (>= a__14 0) (>= a__9 0) (>= a__15 0) (>= a__12 0) (>= a__4 0) (>= a__1 0) (>= a__5 0)))
(check-sat)
;;(get-assignment)
;;(get-model)
(exit)