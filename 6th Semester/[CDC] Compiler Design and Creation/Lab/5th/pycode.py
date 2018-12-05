from Production import * # importing everything from Production

# predefining the set of productions
production = [
  ('E', 'TA'),
  ('A', '+TA'),
  ('A', '#'),
  ('T', 'FB'),
  ('B', '*FB'),
  ('B', '#'),
  ('F', '(E)'),
  ('F', 'i')
]

# creating a intance of the Production class and passing the set of productions
prod = Production(production)

print(prod.showFirstAndFollow())

print(prod.showParsingTable())

test_string = 'i*i+i'

if prod.isValidString(test_string):
  print(test_string + ' is a valid string of the grammar.')
else:
  print(test_string + ' is not a valid string of the grammar.')