#! /bin/bash
GREEN="\033[1;32m"
RED="\033[1;31m"
RESET="\033[0m"

if [[ ! -x ./push_swap ]]; then
    echo -e "${RED}File push_swap not found or not executable${RESET}"
    exit 1
fi

if [[ ! -x ./checker_linux ]]; then
    echo -e "${RED}File checker_linux not found or not executable${RESET}"
    exit 1
fi

ARG="1 2 3 4 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 2 3 5 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 2 4 3 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 2 4 5 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 2 5 3 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 2 5 4 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 3 2 4 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 3 2 5 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 3 4 2 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 3 4 5 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 3 5 2 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 3 5 4 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 4 2 3 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 4 2 5 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 4 3 2 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 4 3 5 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 4 5 2 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 4 5 3 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 5 2 3 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 5 2 4 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 5 3 2 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 5 3 4 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 5 4 2 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="1 5 4 3 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 1 3 4 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 1 3 5 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 1 4 3 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 1 4 5 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 1 5 3 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 1 5 4 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 3 1 4 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 3 1 5 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 3 4 1 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 3 4 5 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 3 5 1 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 3 5 4 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 4 1 3 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 4 1 5 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 4 3 1 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 4 3 5 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 4 5 1 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 4 5 3 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 5 1 3 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 5 1 4 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 5 3 1 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 5 3 4 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 5 4 1 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="2 5 4 3 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 1 2 4 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 1 2 5 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 1 4 2 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 1 4 5 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 1 5 2 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 1 5 4 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 2 1 4 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 2 1 5 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 2 4 1 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 2 4 5 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 2 5 1 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 2 5 4 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 4 1 2 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 4 1 5 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 4 2 1 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 4 2 5 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 4 5 1 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 4 5 2 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 5 1 2 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 5 1 4 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 5 2 1 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 5 2 4 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 5 4 1 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="3 5 4 2 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 1 2 3 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 1 2 5 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 1 3 2 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 1 3 5 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 1 5 2 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 1 5 3 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 2 1 3 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 2 1 5 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 2 3 1 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 2 3 5 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 2 5 1 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 2 5 3 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 3 1 2 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 3 1 5 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 3 2 1 5"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 3 2 5 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 3 5 1 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 3 5 2 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 5 1 2 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 5 1 3 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 5 2 1 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 5 2 3 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 5 3 1 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="4 5 3 2 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 1 2 3 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 1 2 4 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 1 3 2 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 1 3 4 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 1 4 2 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 1 4 3 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 2 1 3 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 2 1 4 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 2 3 1 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 2 3 4 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 2 4 1 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 2 4 3 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 3 1 2 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 3 1 4 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 3 2 1 4"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 3 2 4 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 3 4 1 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 3 4 2 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 4 1 2 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 4 1 3 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 4 2 1 3"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 4 2 3 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 4 3 1 2"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi

ARG="5 4 3 2 1"
moves=`./push_swap $ARG`
tot_moves=$(if [[ -n $moves ]]; then echo "$moves" | wc -l; else echo 0; fi)
checker=$(if [[ -n $moves ]]; then echo "$moves"; else echo -n ""; fi | ./checker_linux $ARG 2>/dev/null)
if (( $tot_moves > 12 )); then
    echo -en "${RED}KO \"$ARG\" $tot_moves moves${RESET}"
else
    echo -en "${GREEN}OK \"$ARG\" $tot_moves moves${RESET}"
fi
if [[ $checker == *OK* ]]; then
	echo -e ",${GREEN} checker OK ${RESET}"
else
	echo -e ",${RED} checker KO ${RESET}"
fi
