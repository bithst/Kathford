operand = [chr(x) for x in range(ord('a'), ord('z') + 1)] + [chr(x) for x in range(ord('A'), ord('Z') + 1)] + ['#', '-']

operator = {'(': 0, '+': 1, '*': 1, '.': 1}

postfix_stack = []
postfix = []

print('Enter a regular expression:')
equation = input()
equation = equation + '#'

RE = ''

for i in range(0, len(equation)):
  char = equation[i]
  if char == '*':
    RE = RE + '*-'
  elif char in operand and equation[i-1] not in ['(', ')', '.', '+']:
    RE = RE + '.' + char
  else:
    RE = RE + char

for char in RE:
  ch = char.upper()

  if ch == '(':
    postfix_stack.append(char)
  elif ch == ')':
    while len(postfix_stack) != 0 and postfix_stack[-1] != '(':
      postfix.append(postfix_stack.pop())
    postfix_stack.pop()
  elif ch in operand:
    postfix.append(char)
  elif ch in operator.keys():
    while len(postfix_stack) != 0 and operator[ch] <= operator[postfix_stack[-1]]:
      postfix.append(postfix_stack.pop())
    postfix_stack.append(char)

while len(postfix_stack) != 0:
  postfix.append(postfix_stack.pop())

syntax_tree = ''.join(postfix)

node_position = []
pos = 1
for node in syntax_tree:
  if node == '-':
    node_position.append(0)
  elif node.upper() in operand:
    node_position.append(pos)
    pos = pos + 1
  else:
    node_position.append(0)

node_data = []
for i in list(range(0, len(syntax_tree))):
  node = syntax_tree[i]
  info = {}
  info['value'] = node

  if node == '-': # - used as placeholder for empty branch of the syntax tree
    node_data.append(info)
  elif node == '_': # _ for empty transition
    info['type'] = 'leaf-node'
    info['nullable'] = True
    info['firstpos'] = []
    info['lastpos'] = []
    node_data.append(info)
  elif node.upper() in operand:
    info['type'] = 'leaf-node'
    info['nullable'] = False
    info['firstpos'] = [node_position[i]]
    info['lastpos'] = [node_position[i]]
    node_data.append(info)
  elif node == '+':
    info['type'] = 'or-node'
    info['nullable'] = node_data[i-2]['nullable'] and node_data[i-1]['nullable']
    info['firstpos'] = list(set().union(node_data[i-2]['firstpos'], node_data[i-1]['firstpos']))
    info['lastpos'] = list(set().union(node_data[i-2]['lastpos'], node_data[i-1]['lastpos']))
    node_data.append(info)
  elif node == '.':
    info['type'] = 'cat-node'
    info['nullable'] = node_data[i-1]['nullable'] and node_data[i-2]['nullable']

    if node_data[i-2]['nullable']:
      info['firstpos'] = list(set().union(node_data[i-2]['firstpos'], node_data[i-1]['firstpos']))
    else:
      info['firstpos'] = node_data[i-2]['firstpos']

    if node_data[i-1]['nullable']:
      info['lastpos'] = list(set().union(node_data[i-2]['lastpos'], node_data[i-1]['lastpos']))
    else:
      info['lastpos'] = node_data[i-1]['lastpos']

    node_data.append(info)
  elif node == '*':
    info['type'] = 'star-node'
    info['nullable'] = True
    info['firstpos'] = node_data[i-2]['firstpos']
    info['lastpos'] = node_data[i-2]['lastpos']
    node_data.append(info) 

followpos = {}
for i in list(range(0, len(node_data))):
  if node_data[i]['value'] == '-':
    continue
  elif node_data[i]['type'] == 'cat-node':
    for x in node_data[i-2]['lastpos']:
      if str(x) in followpos.keys():
        followpos[str(x)] = list(set().union(followpos[str(x)], node_data[i-1]['firstpos']))
      else:
        followpos[str(x)] = []
        followpos[str(x)] = node_data[i-1]['firstpos']
  elif node_data[i]['type'] == 'star-node':
    for x in node_data[i]['lastpos']:
      if str(x) in followpos.keys():
        followpos[str(x)] = list(set().union(followpos[str(x)], node_data[i]['firstpos']))
      else:
        followpos[str(x)] = []
        followpos[str(x)] = node_data[i]['firstpos']
  elif node_data[i]['type'] == 'leaf-node' and node_data[i]['value'] == '#':
    followpos[str(node_position[i])] = []

print('\n{:<20}{:<20}{:<20}{:<20}{:<20}'.format('Value', 'Type', 'Nullable', 'Firstpos', 'Lastpos'))
for data in node_data:
  if data['value'] == '-':
    continue
  for key in data:
    print('{:<20}'.format(str(data[key])), end='')
  print('')

print('\n{:<10}{:<20}'.format('Position', 'Followpos'))
for key in sorted(followpos.keys()):
  print('{:<10}{:<20}'.format(key, str(followpos[key])))