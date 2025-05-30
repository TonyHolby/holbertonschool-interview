#!/usr/bin/python3
"""A script that reads stdin line by line and computes metrics"""

if __name__ == '__main__':
    import sys
    import re
    from collections import defaultdict

    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    valid_status_codes = {
        '200', '301', '400', '401', '403', '404', '405', '500'}

    log_pattern = re.compile(
        r'^(\d{1,3}(?:\.\d{1,3}){3}) - '
        r'\[(.*?)\] "(\w+) (\S+) HTTP/1\.1" (\d{3}) (\d+)$'
        )

    def print_stats():
        print("File size: {}".format(total_size))
        for code in sorted(valid_status_codes):
            if status_counts[code] > 0:
                print(f"{code}: {status_counts[code]}")

    try:
        for line in sys.stdin:
            line = line.strip()
            match = log_pattern.match(line)
            if match:
                status_code = match.group(5)
                file_size = match.group(6)
                total_size += int(file_size)

                if status_code in valid_status_codes:
                    status_counts[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats()

    except KeyboardInterrupt:
        print_stats()
        raise

    print_stats()
