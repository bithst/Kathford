'''
Given a grammar, calculated it's first and follow and also generates a parsing table

Each instance requires a grammar during its initialization as calculations are performed when the object is created.
Grammar should be of the form:
productions = [
  (A, B),
  (C, D),
  ...
]

Where A->B, C->D are the productions of the grammar arranged in a tuple.
Note:
- Starting symbol's production must be the first one in the list.
- '#' should be used to denote an empty transition
- Case insensitive
- All entries must be string. If numbers are to be used, convert them to string using str(<number>) method.
- All terms in the grammer must be single characters; terminals and non-terminals both.

Public methods:
1. Production.showFirstAndFollow()
  Outputs the table on CLI with columns:

  Value - non terminals of the grammar
  First - set of symbols that are firsts of the non-terminal
  Follow - set of symbols that are follows of the non-terminal

2. Production.showParsingTable()
  Outputs the table on CLI with the columns

  Non-terminal - list of non terminals of the grammar
  Input-symbols - list of terminals of the grammar

  Note:
  '-' indicates a error() code on the table cell

3. Production.isValidString(<string>)
  Given an input string, checks whether it lies in the grammar defined by the set of productions and returns true if it does and false if it doesn't.
  Input <string> doesn't need to end with '$'. The program will append it automatically.
'''
class Production():
  def __init__(self, rules):
    self.__rules = []
    self.__nonTerminals = {}
    self.__terms = {}
    for item in rules:
      if self.__checkRule(item) == True:
        self.__rules.append(item)
      else:
        raise ValueError('Invalid data!')
    self.__calculate()

  def __calcPredictiveParsingTable (self):
    for (left, right) in self.__rules:
      if '#' in self.__terms[right[0]]['first']:
        for term in self.__terms[left]['follow']:
          self.__nonTerminals[left][term] = (left, right)
          if '$' in self.__terms[left]['follow']:
            self.__nonTerminals[left]['$'] = (left, right)
      else:
        for term in self.__terms[right[0]]['first']:
          self.__nonTerminals[left][term] = (left, right)

  def __startSymbol(self):
    if len(self.__rules) > 0:
      return self.__rules[0][0]
    else:
      return None

  def __calculate(self):
    self.__calcNonTerminals()
    self.__calcTerms()
    for term in self.__terms.keys():
      self.__calcFirsts(term)
    for term in self.__terms.keys():
      self.__calcFollows(term)
    self.__calcPredictiveParsingTable() 

  def __calcTerms(self):
    for term in list(set(''.join([left + right for (left, right) in self.__rules]))):
      self.__terms[term] = {}

  def __calcNonTerminals(self):
    for nonTerminal in [left for (left, right) in self.__rules]:
      self.__nonTerminals[nonTerminal] = {}

  def __checkRule(self, rule):
    return (type(rule) == tuple and len(rule) == 2)

  def __calcFirsts(self, term):
    if 'first' in self.__terms[term].keys():
      return self.__terms[term]['first']
    self.__terms[term]['first'] = []
    if term not in self.__nonTerminals:
      self.__terms[term]['first'].extend(term)
      return self.__terms[term]['first']
    for (left, right) in self.__rules:
      if left == term:
        for symbol in right:
          if symbol == '#':
            self.__terms[term]['first'].extend('#')
            break
          self.__terms
          if '#' not in self.__calcFirsts(symbol):
            self.__terms[term]['first'].extend(self.__calcFirsts(symbol))
            break
          self.__terms[term]['first'].extend(self.__terms[symbol]['first'][:].remove('#'))
    return self.__terms[term]['first']
    
  def __calcFollows(self, term):
    if 'follow' in self.__terms[term].keys():
      return self.__terms[term]['follow']
    self.__terms[term]['follow'] = []
    if term == self.__rules[0][0]:
      self.__terms[term]['follow'].extend('$')
    for (left, right) in self.__rules:
      if term in right:
        termIndex = right.index(term)
        followIndex = termIndex + 1
        while True:
          if followIndex == len(right):
            if left != term:
              self.__terms[term]['follow'].extend(self.__calcFollows(left))
            break
          if '#' not in self.__terms[right[followIndex]]['first']:
            self.__terms[term]['follow'].extend(self.__terms[right[followIndex]]['first'])
            break
          self.__terms[term]['follow'].extend([char for char in self.__terms[right[followIndex]]['first'] if char != '#'])
          followIndex += 1
        return self.__terms[term]['follow'] 

  def showFirstAndFollow (self):
    strn = ''
    strn += '{:<7}{:<20}{:<20}\n'.format('VALUE', 'FIRST', 'FOLLOW')
    for key in self.__nonTerminals.keys():
      strn += '{:<7}{:<20}{:<20}\n'.format(key, str(self.__terms[key]['first']), str(self.__terms[key]['follow']))
    return strn

  def showParsingTable(self):
    terminals = [X for X in self.__terms if X != '#' and X not in self.__nonTerminals.keys()]
    length = len(terminals) + 1
    strn = ('{:-^{width}}\n'.format('INPUT SYMBOL (TERMINAL)', width=length*15))
    strn += '{:<15}'.format('NON-TERMINAL')
    for item in terminals:
      strn += '{:<15}'.format(item)
    strn += '\n'
    for key in self.__nonTerminals:
      strn += '{:<15}'.format(key)
      for item in terminals:
        if item in self.__nonTerminals[key].keys():
          (left, right) = self.__nonTerminals[key][item]
          strn += '{}->{:<12}'.format(left, right)
        else:
          strn += '{:<15}'.format('-')
      strn += '\n'
    return strn

  def isValidString(self, inputString):
    stack = ['$']
    stack.append(self.__startSymbol())
    inputSymbol = ['$'] + [char for char in reversed(inputString)]

    while stack[-1] != '$':
      tos = stack[-1]
      sym = inputSymbol[-1]

      if tos == sym:
        stack.pop()
        inputSymbol.pop()
      elif tos not in self.__nonTerminals.keys() or sym not in self.__nonTerminals[tos].keys():
        return False
      else:
        stack.pop()
        for item in reversed(self.__nonTerminals[tos][sym][1]):
          if item != '#':
            stack.append(item)
    return True