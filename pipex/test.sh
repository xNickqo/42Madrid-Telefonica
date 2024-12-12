# Define ANSI color codes
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
X='\033[0;35m'
Y='\033[0;36m'
SEP_LINE='\033[0;33m'
NC='\033[0m' # No Color

print_files()
{
	while IFS= read -r line; do
		printf '%s\n' "$line"
	done < "outi"
    echo "$SEP_LINE{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}{.}$NC"
	while IFS= read -r line; do
		printf '%s\n' "$line"
	done < "check"
}

# Function to compare command outputs
compare_outputs() {
    local outi="$1"
    local check="$2"
	local transformer="$3"


    if [ ! -f "$outi" ] || [ ! -f "$check" ]; then
        echo "$RED [KO] Files do not exist or are inaccessible.$NC"
        return 1
    fi
	if [ "$transformer" != "" ]; then
		eval "$transformer" < $outi > "file1"
		rm outi
		mv file1 outi

		eval "$transformer" < $check > "file2"
		rm check
		mv file2 check
	fi

    if [ "$(diff -q outi check)" = "" ]; then
		echo "$GREEN [OK] $NC"
	else
		print_files file1 file2
	fi
	printf "*------------*\n"
}

test() {
    local infile="$1"
    local cmd1="$2"
    local cmd2="$3"
    local outfile="$4"
	local transformer="$5"

    if [ ! -f "pipex" ]; then
        echo "$RED [KO] pipex binary does not exist.$NC"
        return 1
    fi

    make -sC .
	printf "$BLUE $cmd1 | $cmd2:\n $NC"
	start_time=$(date +%s.%N)
    ./pipex $infile "$cmd1" "$cmd2" "$outfile"    ###################### LInea donde esta el comando pipex.
    end_time=$(date +%s.%N)

    pipex_duration=$(scale=3; echo "$end_time - $start_time" | bc)
	pipex_duration=$(printf "%.4f" "$pipex_duration")
	printf "done pipex\n"

	start_time=$(date +%s.%N)
	< $infile | $cmd1 | $cmd2 > "check"
    end_time=$(date +%s.%N)

    bash_duration=$(echo "$end_time - $start_time" | bc	)
	bash_duration=$(printf "%.5f" "$bash_duration")

    # Compare durations
	echo "Bash: ${X}$bash_duration${NC}s"
	echo "Pipe: ${Y}$pipex_duration${NC}s"
	time_diff=$(echo "($bash_duration - $pipex_duration) >= 0.99" | bc)
	if [ $time_diff -gt 0 ]; then
        echo "$RED [KO] process elapse time difference is over 1 second.\n$NC"
		return 1
	fi
    compare_outputs "$outfile" "check" "$transformer"
}

# Example usage
test "infi" "lscpu" "cat -e" "outi"
test "infile" "ls" "ls" "outi"
test "infile" "ping google.com -c 4" "head" "outi"
test "infile" "ps aux" "grep cron" "outi"
test "infile" "sleep 3" "sleep 2" "outi"
test "infile" "sleep 2" "sleep 3" "outi"
test "infile" "cat" "ls" "outi"
test "infile" "srgfg" "cat" "outi"
test "infile" "srgfg" "lkjnf" "outi"
test "infile" "ls" "lkjnf" "outi"
test "infile" "" "cat" "out"
# test "11" "11" "11" "11" "11"
# test "Makefile" "ls" "11" "11" "11"





