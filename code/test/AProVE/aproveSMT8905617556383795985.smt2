(set-info :smt-lib-version 2.6)
(set-logic QF_NIA)
(set-info :source |AProve team, see http://aprove.informatik.rwth-aachen.de/, submitted for SMT-COMP 2014|)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun b__25 () Int)
(declare-fun a__2 () Int)
(declare-fun a__7 () Int)
(declare-fun b__26 () Int)
(declare-fun b__27 () Int)
(declare-fun a__12 () Int)
(declare-fun b__28 () Int)
(declare-fun a__5 () Int)
(declare-fun a__4 () Int)
(declare-fun a__10 () Int)
(declare-fun a__6 () Int)
(declare-fun a__3 () Int)
(declare-fun a__8 () Int)
(declare-fun a__11 () Int)
(declare-fun a__16 () Int)
(declare-fun a__17 () Int)
(declare-fun a__13 () Int)
(declare-fun a__18 () Int)
(declare-fun a__14 () Int)
(declare-fun a__15 () Int)
(declare-fun a__19 () Int)
(declare-fun a__20 () Int)
(declare-fun a__21 () Int)
(declare-fun a__22 () Int)
(declare-fun a__23 () Int)
(declare-fun a__24 () Int)
(declare-fun a__9 () Int)
(assert (and (>= (+ 1 (* (- 0 1) b__25)) 0) (= (+ (* b__25 a__2 a__7) (* (- 0 1) (* a__2 a__7))) 0) (>= (+ 1 (* (- 0 1) b__26)) 0) (= (+ (* b__26 a__2) (* (- 0 1) a__2)) 0) (>= (+ 1 (* (- 0 1) b__27)) 0) (= (+ (* b__27 a__2 a__12) (* (- 0 1) (* a__2 a__12))) 0) (>= (+ 1 (* (- 0 1) b__28)) 0) (= (+ (* b__28 a__2 a__5) (* (- 0 1) (* a__2 a__5))) 0) (>= (+ (* b__25 a__4 a__10) (* (- 0 1) b__25)) 0) (>= (+ (* b__26 a__6) (* b__26 a__3 a__8) (* (- 0 1) (* b__26 a__11)) (* (- 0 1) (* b__26 a__16 a__12))) 0) (>= (+ (* b__26 a__7) (* (- 0 1) (* b__26 a__17 a__12)) (* (- 0 1) (* b__26 a__13))) 0) (>= (+ (* b__26 a__4 a__8) (* (- 0 1) (* b__26 a__18 a__12)) (* (- 0 1) (* b__26 a__14))) 0) (>= (+ (* b__26 a__5 a__8) (* (- 0 1) (* b__26 a__15))) 0) (>= (+ (* b__26 a__11) (* b__26 a__19 a__12) (* (- 0 1) (* b__26 a__3)) (* (- 0 1) (* b__26 a__6 a__5))) 0) (>= (+ (* b__26 a__13) (* (- 0 1) (* b__26 a__7 a__5))) 0) (>= (+ (* b__26 a__14) (* (- 0 1) (* b__26 a__4))) 0) (>= (+ (* b__26 a__15) (* (- 0 1) (* b__26 a__8 a__5))) 0) (>= (+ (* b__27 a__16) (* b__27 a__20 a__17) (* b__27 a__20 a__18) (* (- 0 1) (* b__27 a__21))) 0) (>= (+ (* b__27 a__16) (* b__27 a__20 a__17) (* b__27 a__22 a__18) (* (- 0 1) (* b__27 a__19))) 0) (>= (+ (* b__27 a__16) (* b__27 a__22 a__17) (* b__27 a__20 a__18) (* (- 0 1) (* b__27 a__19))) 0) (>= (+ (* b__27 a__23 a__17) (* (- 0 1) (* b__27 a__17))) 0) (>= (+ (* b__27 a__23 a__18) (* (- 0 1) (* b__27 a__18))) 0) (>= (+ (* b__26 a__15) (* (- 0 1) b__26)) 0) (>= (+ (* b__28 a__6) (* b__28 a__24 a__8) (* (- 0 1) (* b__28 a__24))) 0) (>= (+ (* a__3 a__2) (* (- 0 1) (* a__6 a__2)) (* (- 0 1) (* a__9 a__7 a__2)) (* (- 0 1) (* a__3 a__10 a__7 a__2)) (* (- 0 1) (* a__3 a__8 a__2)) (- 0 1)) 0) (>= (+ (* a__4 a__2) (* (- 0 1) (* a__4 a__10 a__7 a__2)) (* (- 0 1) (* a__4 a__8 a__2))) 0) (>= (+ (* a__5 a__2) (* (- 0 1) (* a__5 a__10 a__7 a__2)) (* (- 0 1) (* a__5 a__8 a__2))) 0) (>= b__25 0) (>= 1 b__25) (>= a__2 0) (>= a__7 0) (>= b__26 0) (>= 1 b__26) (>= b__27 0) (>= 1 b__27) (>= a__12 0) (>= b__28 0) (>= 1 b__28) (>= a__5 0) (>= a__4 0) (>= a__10 0) (>= a__6 0) (>= a__3 0) (>= a__8 0) (>= a__11 0) (>= a__16 0) (>= a__17 0) (>= a__13 0) (>= a__18 0) (>= a__14 0) (>= a__15 0) (>= a__19 0) (>= a__20 0) (>= a__21 0) (>= a__22 0) (>= a__23 0) (>= a__24 0) (>= a__9 0)))
(check-sat)
;;(get-assignment)
;;(get-model)
(exit)
