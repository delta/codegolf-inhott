fact = []
fact.push(1)
for (let i=1; i<20; i++)
    fact.push(i * fact[i - 1])


visited = new Set
c0 = [], c = [];
for (let i=0; i<10; i++) {
    c0.push(0), c.push(0)
}

const setCount = (s, lst) => {
    for (let i=0; i<10; i++)
        lst[i] = 0
    for (let i=0; i<s.length; i++)
        lst[Number(s[i])] += 1
}


const getPerms = () => {
    ans = fact[c.reduce((a, b) => a + b, 0)]
    for (let i=0; i<10; i++)
        ans /= fact[c[i]]
    return ans
}

const getAns = (s) => {
    setCount(s, c)

    for (let i=0; i<10; i++) {
        if (c0[i] && !c[i])
            return 0
    }

    s = s.split('').sort().reduce((a, b) => a + b)

    if (visited.has(s))
        return 0
    visited.add(s)

    ans = getPerms()
    if (c[0] > 0) {
        c[0] -= 1
        ans -= getPerms()
    }

    return ans
}

function processData(input) {
    const n = input;
    const k = n.length;

    setCount(n, c0);

    let ans = 0;
    for (let i=1; i<=(1<<k); i++) {
        let s = "";
        for (let j=0; j<k; j++) {
            if (i & (1<<j)) s += n[j];
        }
        ans += getAns(s);
    }
    process.stdout.write(String(ans));
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
