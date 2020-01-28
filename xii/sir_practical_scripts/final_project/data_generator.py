from name_set import first_names, last_names
import enum
import random

class Student :
  def __init__(self, name, roll_no, subject_list) :
    if type(name) != str :
      raise TypeError("Inappropriate type of argument 1 called 'name'")
    if type(roll_no) != int :
      raise TypeError("Inappropriate type of argument 2 called 'roll_no'")
    if not all(isinstance(sub, int) for sub in subject_list) :
      raise TypeError("Inappropriate type of elements argument 3 called 'subject_list'")
    self.name = name
    self.roll_no = roll_no
    self.subject_list = subject_list.copy()

  def printSelf(self) :
    print(self.name, end='\n')
    print(self.roll_no, end='\n')
    # Unpack `subject_list` into arguments for `print` and print each separated by a space
    print(*(self.subject_list), sep=' ', end='\n')

class RollNoOptions(enum.Enum) :
  RANGE = 1
  RANDOM = 2

class RollNoSettings :
  def __init__(self, option, **kwargs):
    if option == RollNoOptions.RANGE :
      if (type(kwargs['lower']) != int) :
        raise TypeError("Inappropriate type for kwarg 'lower'")
      if (type(kwargs['upper']) != int) :
        raise TypeError("Inappropriate type for kwarg 'upper'")
      self._value_ = RollNoOptions.RANGE
      self.upper_limit = kwargs['upper']
      self.lower_limit = kwargs['lower']
    elif option == RollNoOptions.RANDOM :
      if (type(kwargs['max_rand']) != int) :
        raise TypeError("Inappropriate type for kwarg 'max_rand'")
      self._value_ = RollNoOptions.RANDOM
      self.max_random = kwargs['max_rand']

class SubjectSetOptions(enum.Enum) :
  GIVEN_SETS = 1
  RANDOM_FROM_SET = 2
  PURELY_RANDOM = 3

class SubjectSetSettings :
  def __init__(self, option, **kwargs) :
    if option == SubjectSetOptions.PURELY_RANDOM :
      if (type(kwargs['max_rand']) != int) :
        raise TypeError("Inappropriate type for kwarg 'max_rand'")
      if (type(kwargs['codes_per_set']) != int) :
        raise TypeError("Inappropriate type of kwarg 'codes_per_set'")
      self._value_ = SubjectSetOptions.PURELY_RANDOM
      self.max_random = kwargs['max_rand']
      self.codes_per_set = kwargs['codes_per_set']
    elif option == SubjectSetOptions.RANDOM_FROM_SET :
      if (not all(isinstance(sub, int) for sub in kwargs['subject_codes'])) :
        raise TypeError("Inappropriate type of elements kwarg 'subject_codes'")
      if (type(kwargs['codes_per_set']) != int) :
        raise TypeError("Inappropriate type of kwarg 'codes_per_set'")
      self._value_ = SubjectSetOptions.RANDOM_FROM_SET
      self.subject_codes = kwargs['subject_codes'].copy()
      self.codes_per_set = kwargs['codes_per_set']
    elif option == SubjectSetOptions.GIVEN_SETS :
      if (not all(isinstance(sub, int) for x in kwargs['subject_sets'] for sub in x)) :
        raise TypeError("Inappropriate type of elements kwarg 'subject_sets'")
      self._value_ = SubjectSetOptions.GIVEN_SETS
      self.subject_sets = kwargs['subject_sets'].copy()

class Settings :
  def __init__(self, roll_op, sub_op) :
    if type(roll_op) != RollNoSettings :
      raise TypeError("Inappropriate type of argument 1 called 'roll_op'")
    if type(sub_op) != SubjectSetSettings :
      raise TypeError("Inappropriate type of argument 2 called 'sub_op'")
    self.roll_no_settings = roll_op
    self.subject_set_settings = sub_op

def getSettings() :
  while True :
    try :
      roll_op = RollNoOptions(int(input("1 - in a range\n"
                                          "2 - randomly\n"
                                          "How to generate roll no.s? ")))
    except ValueError :
      print("ValueError : Please try again\n")
    else :
      break
  if roll_op is RollNoOptions.RANGE :
    while True :
      try :
        lowr = int(input("Enter lower limit(>=) : "))
        uppr = int(input("Enter upper limit (<) : "))
      except ValueError :
        print("ValueError : Please try again\n")
      else :
        if (lowr >= uppr) :
          print("ValueError : upper limit must be greater than the lower limit\n")
          continue
        else :
          break
    roll_op = RollNoSettings(roll_op, upper = uppr, lower = lowr)
  else :
    while True :
      try :
        rand_max = int(input("Enter maximum value : "))
      except ValueError :
        print("ValueError : Please try again\n")
      else :
        break
    roll_op = RollNoSettings(roll_op, max_rand = rand_max)

  print()

  while True :
    try :
      sub_op = SubjectSetOptions(int(input("1 - from a given set of subject sets\n"
                                           "2 - any set from given subject codes\n"
                                           "3 - entirely random values\n"
                                           "How to generate roll no.s? ")))
    except ValueError :
      print("ValueError : Please try again\n")
    else :
      break
  if sub_op is SubjectSetOptions.GIVEN_SETS :
    while True :
      try :
        set_length = int(input("Enter no. of codes per set : "))
        no_of_sets = int(input("Enter no. of sets : "))
      except ValueError :
        print("ValueError : Please try again\n")
      else :
        if set_length < 1 or no_of_sets < 1 :
          continue
        else :
          break
    sub_sets = []
    for i in range(no_of_sets) :
      sub_set = []
      for j in range(set_length) :
        while True :
          try :
            sub_set.append(int(input("Enter a the %dth code of %dth set : " % (j+1,i+1))))
          except ValueError :
            print("ValueError : Please try again\n")
          else :
            break
      sub_sets.append(sub_set)
    sub_op = SubjectSetSettings(sub_op, subject_sets = sub_sets)
  elif sub_op is SubjectSetOptions.RANDOM_FROM_SET :
    while True :
      try :
        no_of_codes = int(input("Enter no. of codes : "))
        codes_in_set = int(input("Enter no. of codes per set : "))
      except ValueError :
        print("ValueError : Please try again\n")
      else :
        break
    sub_codes = []
    for i in range(no_of_codes) :
      while True :
          try :
            sub_codes.append(int(input("Enter a the %dth code : " % (i+1))))
          except ValueError :
            print("ValueError : Please try again\n")
          else :
            break
    sub_op = SubjectSetSettings(sub_op, subject_codes = sub_codes, codes_per_set = codes_in_set)
  else :
    while True :
      try :
        rand_max = int(input("Enter maximum value : "))
        codes_in_set = int(input("Enter no. of codes per set : "))
      except ValueError :
        print("ValueError : Please try again\n")
      else :
        break
    sub_op = SubjectSetSettings(sub_op, max_rand = rand_max, codes_per_set = codes_in_set)
  return Settings(roll_op, sub_op)

if __name__ == '__main__' :
  students = []
  no_of_students = int(input("No. of students? "))
  print()
  
  settings = getSettings()

  for i in range(no_of_students) :
    name = random.choice(first_names)
    name = name + ' ' + random.choice(last_names)

    if settings.roll_no_settings._value_ is RollNoOptions.RANGE :
      roll_no = settings.roll_no_settings.lower_limit + i % (settings.roll_no_settings.upper_limit-settings.roll_no_settings.lower_limit)
    else :
      roll_no = random.randint(0, settings.roll_no_settings.max_random)

    if settings.subject_set_settings._value_ is SubjectSetOptions.GIVEN_SETS :
      subject_set = random.choice(settings.subject_set_settings.subject_sets)
    elif settings.subject_set_settings._value_ is SubjectSetOptions.RANDOM_FROM_SET :
      subject_set = random.sample(settings.subject_set_settings.subject_codes, settings.subject_set_settings.codes_per_set)
    else :
      subject_set = []
      for i in range(settings.subject_set_settings.codes_per_set) :
        subject_set.append(random.randint(0, settings.subject_set_settings.max_random))

    students.append(Student(name, roll_no, subject_set))

  print()
  
  print("Output : ", end ='')
  print("=========", end ='\n\n')
  for stu in students :
    stu.printSelf()
  
