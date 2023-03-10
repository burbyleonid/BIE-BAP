(set-logic ALL)
(set-option :produce-models true)
(declare-fun x () Int)
(declare-fun y () Int)
(declare-fun z () Int)


(assert (and ( < 5 x) (>= y 10) (= (+ x y) z)))

(check-sat)
(get-model)
