#Name: Sofen Hoque Anonta
__metaclass__ = type

# take space seperated numbers (of specified type) as input and return them as a list
def input_array(TYPE):
    return [TYPE(x) for x in raw_input().split()]  #put seperator in split(), by default it's " "


# ####################################################
