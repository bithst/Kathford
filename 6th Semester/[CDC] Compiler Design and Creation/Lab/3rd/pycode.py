from Production import Production

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

prod = Production(production)

print(prod.showFirstAndFollow())