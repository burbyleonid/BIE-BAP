(set-logic ALL)
(set-option :produce-models true)
(declare-fun x () Int)
(declare-fun y () Int)
(declare-fun z () Int)


(assert (and (< 0 z)( < 10 x) (>= y (* 2 x)) (= (* x y) z)))

(check-sat)
(get-model)
