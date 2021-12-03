var fs = require('fs');
const currentET = Math.floor(new Date().getTime() / 1000);

fs.writeFileSync('timefile.timefile', `${currentET}`);
