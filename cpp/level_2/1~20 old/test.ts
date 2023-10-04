type PredicateFn = (value: any, index?: number) => boolean;

const or = (...predicates: PredicateFn[]): PredicateFn => {
  return (value) => predicates.some((predicate) => predicate(value));
};

const get_true = (v: boolean) => true;
const get_false = (v: boolean) => false;

const val = or(get_true, get_false)(true);

[].filter(or(get_true, get_false));

console.log(val);
