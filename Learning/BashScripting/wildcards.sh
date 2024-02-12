#!/bin/bash
# * - matches 0 or more characters(*.txt, a*, a*t.xt)
# ? - matches exactly one character (?.txt, a?, a?.txt)
# [] - character class - matches any of the characters included: [aeiou], ca[nt]*
# [!] - same but are NOT included - [!aeiou]
# [a-g]*
# [[:alpha:]] [[:alnum:]] [[:digit:]] [[:lower:]] [[:space:]] [[:upper:]]