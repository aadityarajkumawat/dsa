function hashStringToInt(s, tableSize) {
    let hash = 17;
    for (let i = 0; i < s.length; i++) {
        hash = (13 * hash * s.charCodeAt(i)) % tableSize;
    }
    return hash;
}

class HashTable {
    table = new Array(3);
    setItem = (key, value) => {
        const idx = hashStringToInt(key, this.table.length);
        if (this.table[idx]) {
            this.table[idx].push([key, value]);
        }
        this.table[idx] = [[key, value]];
    };
    getitem = (key) => {
        const idx = hashStringToInt(key, this.table.length);
        if (!this.table[idx]) return null;
        console.log(this.table[idx].find((x) => x[0] === key));
        return this.table[idx].find((x) => x[0] === key)[1];
    };
}

const myTable = new HashTable();
myTable.setItem("firstname", "Bob");
myTable.setItem("lastname", "tim");
myTable.setItem("age", 5);
myTable.setItem("dob", "1/2/3");

console.log(myTable.table);

console.log(myTable.getitem("firstname"));
console.log(myTable.getitem("lastname"));
console.log(myTable.getitem("age"));
console.log(myTable.getitem("dob"));
