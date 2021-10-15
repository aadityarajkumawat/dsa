const util = require("util");
const exec = util.promisify(require("child_process").exec);

let command =
    "clear && g++ -o main ListNode.cpp pll.cpp && ./main && rm ./main";

exec(command, (err, stdout, _) => {
    if (err) {
        console.error(err);
    } else {
        console.log(`${stdout}`);
    }
});
