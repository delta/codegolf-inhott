const charCodeOfA = 'a'.charCodeAt(0)

function processData(input) {
    cnt = []
    starts = []
    let placeVal = 1, len
    for (let i=0; i<10; i++) {
        cnt.push([0, i])
        starts.push(false);
    }
    
    const data = input.split('\n')
    const n = Number(data[0]);
    for (let _=0; _<n; _++) {
        const s = data[_ + 1];
        placeVal = 1;
        len = s.length;
        for (let i=len-1; i>=0; i--) {
            cnt[s.charCodeAt(i) - charCodeOfA][0] += placeVal;
            placeVal *= 10;
        }
        starts[s.charCodeAt(0) - charCodeOfA] = true;
    }
    
    cnt.sort((a, b) => a[0] > b[0])
    let digit = 1, ans = 0, flag = true;

    for (let i=9; i>=0; i--) {
        if (!starts[cnt[i][1]] && flag) flag = false;
        else {
            ans += cnt[i][0] * digit;
            digit++;
        }
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
