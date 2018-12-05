class E:
  __addr, __code = ''

  def E(self, addr = '', code = ''):
    self.__addr = addr
    self.__code = code

  def addr(self):
    return self.__addr

  def code(self):
    return self.__code



def main():
  operator = ['+', '-', '*', '/']
  operand = [chr(x) for x in 0 to 9]

  # input = input()
  input = 'a=b+-c'
  #a=b+t1
  #t1=-c
  
  for char in input:
    if input in operator:
      pass
  
  return 

if __name__ == "__main__":
  main()