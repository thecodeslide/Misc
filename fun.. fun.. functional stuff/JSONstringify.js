const stringifyJSON = (val) => {
  // let str = '';
  if(val instanceof Date) return `"` + val.toJSON() + `"`;
  if (typeof val === 'object') {
    if (val === null) return String(val);
    if (Array.isArray(val)) {
      // for(const i of val) str += ',' + stringifyJSON(i);
      // return `[` + str.slice(1) + `]`;
      return `[` + val.map(v => stringifyJSON(v)) + `]`;
    }
    // Object.getPrototypeOf({}) === Object.prototype
    let str = '';
    for (const i in val) {
      if (val[i] !== undefined && typeof val[i] !== 'function') {
        str += `,"` + i + `":` + stringifyJSON(val[i]);
      }
    }
    return `{` + str.slice(1) + `}`;
  }
  if (typeof val === 'number' || typeof val === 'boolean') return String(val);
  if (typeof val === 'string') return `"` + val + `"`;

};
