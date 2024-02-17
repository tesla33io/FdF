#!/bin/bash

# Reset all text attributes
reset='\033[0m'

# Regular Colors
black='\033[0;30m'
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
purple='\033[0;35m'
cyan='\033[0;36m'
white='\033[0;37m'

# Bold Colors
bold_black='\033[1;30m'
bold_red='\033[1;31m'
bold_green='\033[1;32m'
bold_yellow='\033[1;33m'
bold_blue='\033[1;34m'
bold_purple='\033[1;35m'
bold_cyan='\033[1;36m'
bold_white='\033[1;37m'

# Underline Colors
underline_black='\033[4;30m'
underline_red='\033[4;31m'
underline_green='\033[4;32m'
underline_yellow='\033[4;33m'
underline_blue='\033[4;34m'
underline_purple='\033[4;35m'
underline_cyan='\033[4;36m'
underline_white='\033[4;37m'

# Background Colors
background_black='\033[40m'
background_red='\033[41m'
background_green='\033[42m'
background_yellow='\033[43m'
background_blue='\033[44m'
background_purple='\033[45m'
background_cyan='\033[46m'
background_white='\033[47m'

# High Intensity Colors
intense_black='\033[0;90m'
intense_red='\033[0;91m'
intense_green='\033[0;92m'
intense_yellow='\033[0;93m'
intense_blue='\033[0;94m'
intense_purple='\033[0;95m'
intense_cyan='\033[0;96m'
intense_white='\033[0;97m'

# Bold High Intensity Colors
bold_intense_black='\033[1;90m'
bold_intense_red='\033[1;91m'
bold_intense_green='\033[1;92m'
bold_intense_yellow='\033[1;93m'
bold_intense_blue='\033[1;94m'
bold_intense_purple='\033[1;95m'
bold_intense_cyan='\033[1;96m'
bold_intense_white='\033[1;97m'

# High Intensity Background Colors
background_intense_black='\033[0;100m'
background_intense_red='\033[0;101m'
background_intense_green='\033[0;102m'
background_intense_yellow='\033[0;103m'
background_intense_blue='\033[0;104m'
background_intense_purple='\033[0;105m'
background_intense_cyan='\033[0;106m'
background_intense_white='\033[0;107m'

pause() {
	read -n 1 -s -p "$(echo -e "${yellow}Press any key to continue...${reset}")";echo
}

echo -e "${bold_green}Run Make${reset}"
make

pause

echo -e "${bold_blue}check for relinking${reset}"
make
make
make

pause

echo -e "${purple}GROUP 1: Args${reset}"
echo -e "\t${purple}-- no args ${reset}"
echo ./fdf && ./fdf
echo -e "\t${purple}-- invalid arg${reset}"
echo ./fdf hello && ./fdf hello
echo -e "\t${purple}-- too many args${reset}"
echo ./fdf 1 2 3 4 5 6 7 8 9 0 && ./fdf 1 2 3 4 5 6 7 8 9 0
echo -e "\t${purple}-- not .fdf file${reset}"
echo ./fdf Makefile && ./fdf Makefile

pause

echo -e "${purple}GROUP 2: Basic test${reset}"
echo -e "\t${purple}-- 42 map ${reset}"
cat <<EOF >map.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 50 50  0  0 50 50  0  0  0 50 50 50 50 50  0  0  0
0  0 50 50  0  0 50 50  0  0  0  0  0  0  0 50 50  0  0
0  0 50 50  0  0 50 50  0  0  0  0  0  0  0 50 50  0  0
0  0 50 50 50 50 50 50  0  0  0  0 50 50 50 50  0  0  0
0  0  0 50 50 50 50 50  0  0  0 50 50  0  0  0  0  0  0
0  0  0  0  0  0 50 50  0  0  0 50 50  0  0  0  0  0  0
0  0  0  0  0  0 50 50  0  0  0 50 50 50 50 50 50  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
EOF
echo "./fdf map.fdf" && valgrind ./fdf map.fdf
pause
rm -f map.fdf
echo -e "\t${purple}-- flat map ${reset}"
cat <<EOF >map.fdf
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
EOF
echo "./fdf map.fdf" && valgrind ./fdf map.fdf
pause
rm -f map.fdf
echo -e "\t${purple}-- one point up map ${reset}"
cat <<EOF >map.fdf
10 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
EOF
echo "./fdf map.fdf" && valgrind ./fdf map.fdf
pause
rm -f map.fdf
echo -e "\t${purple}-- big random map (42x42, from -10z to 10z) ${reset}"
python3 ~/map-gen.py -10 10 42 42 > map.fdf
echo "./fdf map.fdf" && valgrind ./fdf map.fdf
pause
rm -f map.fdf
echo -e "\t${purple}-- really big map (from you) ${reset}"
echo -e "\n${bold_green}Pleas provide full path to the file of a really big map (like t1 or t2, or mars)${reset}\n"
read -p "Enter path to the map: " usermap
echo "./fdf ${usermap}" && valgrind ./fdf $usermap
read -n 1 -s -p "$(echo -e "${bold_green}That's it! Hope everything was fine :)${reset}\nPress a key one more time.")";echo
