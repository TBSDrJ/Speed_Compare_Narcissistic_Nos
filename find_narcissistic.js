function get_digits(n) {
    digits = [];
    while (n > 0) {
        digits.push(n % 10);
        n = Math.floor(n/10);
    }
    return digits;
}

function main() {
    chars = 0;
    for (i=1; i<10000000; i++) {
        digs = get_digits(i);
        narcissistic_sum = 0;
        for (j=0; j<digs.length; j++) {
            narcissistic_sum += Math.pow(digs[j], digs.length);
        }
        if (narcissistic_sum == i) {
            p_tag.innerHTML += i + " ";
            chars += digs.length + 1;
            if (chars > 70) {
                p_tag.innerHTML += "<br />";
                chars = 0;
            }
        }
    }
    p_tag.innerHTML += "<br />";
}

p_tag = document.getElementById("number_list");
start = new Date();
main()
end = new Date();
elapsed = end.valueOf() - start.valueOf();
p_tag.innerHTML += elapsed + "<br />";
