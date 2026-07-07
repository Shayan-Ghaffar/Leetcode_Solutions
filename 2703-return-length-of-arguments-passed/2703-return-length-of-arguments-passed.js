/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
 let v = args.length
 return v
};

/**
 * argumentsLength(1, 2, 3); // 3
 */