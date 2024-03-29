(set-info :smt-lib-version 2.6)
(set-logic QF_NIA)
(set-info :source |AProve team, see http://aprove.informatik.rwth-aachen.de/, submitted for SMT-COMP 2014|)
(set-info :category "industrial")
(set-info :status sat)
(declare-fun b__37 () Int)
(declare-fun a__5 () Int)
(declare-fun a__2 () Int)
(declare-fun a__32 () Int)
(declare-fun a__3 () Int)
(declare-fun b__38 () Int)
(declare-fun a__9 () Int)
(declare-fun a__18 () Int)
(declare-fun a__15 () Int)
(declare-fun a__13 () Int)
(declare-fun a__7 () Int)
(declare-fun a__10 () Int)
(declare-fun a__16 () Int)
(declare-fun a__6 () Int)
(declare-fun a__21 () Int)
(declare-fun a__23 () Int)
(declare-fun a__8 () Int)
(declare-fun a__25 () Int)
(declare-fun a__19 () Int)
(declare-fun a__26 () Int)
(declare-fun a__24 () Int)
(declare-fun a__27 () Int)
(declare-fun a__22 () Int)
(declare-fun a__11 () Int)
(declare-fun a__12 () Int)
(declare-fun a__14 () Int)
(declare-fun a__28 () Int)
(declare-fun a__29 () Int)
(declare-fun a__30 () Int)
(declare-fun a__31 () Int)
(declare-fun a__33 () Int)
(declare-fun a__34 () Int)
(declare-fun a__17 () Int)
(declare-fun a__35 () Int)
(declare-fun a__36 () Int)
(declare-fun a__1 () Int)
(declare-fun a__4 () Int)
(declare-fun a__20 () Int)
(assert (and (>= (+ 1 (* (- 0 1) b__37)) 0) (= (+ (* b__37 a__5) (* (- 0 1) a__5)) 0) (= (+ (* b__37 a__2 a__32) (* (- 0 1) (* a__2 a__32))) 0) (= (+ (* b__37 a__3 a__32) (* (- 0 1) (* a__3 a__32))) 0) (>= (+ 1 (* (- 0 1) b__38)) 0) (= (+ (* b__38 a__2) (* (- 0 1) a__2)) 0) (= (+ (* b__38 a__3) (* (- 0 1) a__3)) 0) (>= (+ a__2 (* (- 0 1) (* a__9 a__5)) (* (- 0 1) (* a__18 a__15 a__13 a__7))) 0) (>= (+ a__3 (* (- 0 1) (* a__10 a__5)) (* (- 0 1) (* a__16 a__13 a__7))) 0) (>= (+ a__6 (* (- 0 1) a__21)) 0) (>= (+ (* a__13 a__21) (* (- 0 1) a__21)) 0) (>= (+ (* a__15 a__21) (* (- 0 1) (* a__23 a__2))) 0) (>= (+ (* a__16 a__21) (* (- 0 1) (* a__23 a__3))) 0) (>= (+ (* a__18 a__21) (* (- 0 1) a__21)) 0) (>= (+ a__7 (* (- 0 1) a__21)) 0) (>= (+ (* b__37 a__8) (* b__37 a__25 a__9) (* (- 0 1) (* b__37 a__19))) 0) (>= (+ (* b__37 a__8) (* b__37 a__26 a__9) (* b__37 a__25 a__10) (* (- 0 1) (* b__37 a__24))) 0) (>= (+ (* b__37 a__27 a__9) (* (- 0 1) (* b__37 a__9))) 0) (>= (+ (* b__37 a__27 a__10) (* (- 0 1) (* b__37 a__10))) 0) (>= (+ (* b__38 a__22) (* b__38 a__11 a__23) (* (- 0 1) (* b__38 a__25))) 0) (>= (+ (* b__38 a__22) (* b__38 a__12 a__23) (* (- 0 1) (* b__38 a__26)) (* (- 0 1) (* b__38 a__22 a__27))) 0) (>= (+ (* b__38 a__13 a__23) (* (- 0 1) (* b__38 a__23 a__27))) 0) (>= (+ (* b__38 a__22) (* b__38 a__14 a__23) (* (- 0 1) (* b__38 a__28)) (* (- 0 1) (* b__38 a__22 a__29)) (* (- 0 1) (* b__38 a__22 a__30))) 0) (>= (+ (* b__38 a__15 a__23) (* (- 0 1) (* b__38 a__23 a__29))) 0) (>= (+ (* b__38 a__16 a__23) (* (- 0 1) (* b__38 a__23 a__30))) 0) (>= (+ (* b__38 a__28) (* (- 0 1) (* b__38 a__31)) (* (- 0 1) (* b__38 a__8 a__32)) (* (- 0 1) (* b__38 a__11 a__33)) (* (- 0 1) (* b__38 a__12 a__34)) (* (- 0 1) (* b__38 a__14 a__13 a__34)) (* (- 0 1) (* b__38 a__17 a__15 a__13 a__34))) 0) (>= (+ (* b__38 a__29) (* (- 0 1) (* b__38 a__9 a__32)) (* (- 0 1) (* b__38 a__18 a__15 a__13 a__34))) 0) (>= (+ (* b__38 a__30) (* (- 0 1) (* b__38 a__10 a__32)) (* (- 0 1) (* b__38 a__16 a__13 a__34))) 0) (>= (+ (* b__38 a__31) (* b__38 a__19 a__32) (* (- 0 1) (* b__38 a__22))) 0) (>= (+ (* b__38 a__33) (* (- 0 1) (* b__38 a__23))) 0) (>= (+ (* b__38 a__31) (* b__38 a__24 a__32) (* (- 0 1) (* b__38 a__22))) 0) (>= (+ (* b__38 a__34) (* (- 0 1) (* b__38 a__23))) 0) (>= (+ (* b__38 a__22) (* b__38 a__17 a__23) (* (- 0 1) (* b__38 a__35)) (* (- 0 1) (* b__38 a__22 a__36))) 0) (>= (+ (* b__38 a__18 a__23) (* (- 0 1) (* b__38 a__23 a__36))) 0) (>= (+ (* b__38 a__23) (* (- 0 1) b__38)) 0) (>= (+ (* b__38 a__26) (* (- 0 1) (* b__38 a__12))) 0) (>= (+ (* b__38 a__27) (* (- 0 1) (* b__38 a__13))) 0) (>= (+ (* b__38 a__28) (* (- 0 1) (* b__38 a__14))) 0) (>= (+ (* b__38 a__29) (* (- 0 1) (* b__38 a__15))) 0) (>= (+ (* b__38 a__30) (* (- 0 1) (* b__38 a__16))) 0) (>= (+ (* b__38 a__35) (* b__38 a__25 a__36) (* (- 0 1) (* b__38 a__25))) 0) (>= (+ (* b__38 a__27 a__36) (* (- 0 1) b__38)) 0) (>= (+ (* b__38 a__35) (* (- 0 1) (* b__38 a__17))) 0) (>= (+ (* b__38 a__36) (* (- 0 1) (* b__38 a__18))) 0) (>= (+ (* b__38 a__25) (* (- 0 1) (* b__38 a__11))) 0) (>= (+ a__1 (* (- 0 1) a__4) (* (- 0 1) (* a__8 a__5)) (* (- 0 1) (* a__11 a__6)) (* (- 0 1) (* a__12 a__7)) (* (- 0 1) (* a__14 a__13 a__7)) (* (- 0 1) (* a__17 a__15 a__13 a__7))) 0) (>= (+ a__4 (* a__19 a__5) (* (- 0 1) a__20)) 0) (>= (* a__12 a__21) 0) (>= (+ a__20 (* a__14 a__21) (* (- 0 1) a__1) (* (- 0 1) (* a__22 a__2)) (* (- 0 1) (* a__22 a__3))) 0) (>= (* a__17 a__21) 0) (>= (+ a__4 (* a__24 a__5) (* (- 0 1) a__20)) 0) (not (and (= (+ a__1 (* (- 0 1) a__4) (* (- 0 1) (* a__8 a__5)) (* (- 0 1) (* a__11 a__6)) (* (- 0 1) (* a__12 a__7)) (* (- 0 1) (* a__14 a__13 a__7)) (* (- 0 1) (* a__17 a__15 a__13 a__7))) 0) (= (+ a__4 (* a__19 a__5) (* (- 0 1) a__20)) 0) (= (* a__12 a__21) 0) (= (+ a__20 (* a__14 a__21) (* (- 0 1) a__1) (* (- 0 1) (* a__22 a__2)) (* (- 0 1) (* a__22 a__3))) 0) (= (* a__17 a__21) 0) (= (+ a__4 (* a__24 a__5) (* (- 0 1) a__20)) 0))) (>= b__37 0) (>= 1 b__37) (>= a__5 0) (>= a__2 0) (>= a__32 0) (>= a__3 0) (>= b__38 0) (>= 1 b__38) (>= a__9 0) (>= a__18 0) (>= a__15 0) (>= a__13 0) (>= a__7 0) (>= a__10 0) (>= a__16 0) (>= a__6 0) (>= a__21 0) (>= a__23 0) (>= a__8 0) (>= a__25 0) (>= a__19 0) (>= a__26 0) (>= a__24 0) (>= a__27 0) (>= a__22 0) (>= a__11 0) (>= a__12 0) (>= a__14 0) (>= a__28 0) (>= a__29 0) (>= a__30 0) (>= a__31 0) (>= a__33 0) (>= a__34 0) (>= a__17 0) (>= a__35 0) (>= a__36 0) (>= a__1 0) (>= a__4 0) (>= a__20 0)))
(check-sat)
;;(get-assignment)
;;(get-model)
(exit)
