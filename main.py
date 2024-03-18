from transformers import BertModel, AutoTokenizer
import pandas as pd

model_name = "bert-base-cased"
#write an example of a bert
tokenizer = AutoTokenizer.from_pretrained(model_name)
model = BertModel.from_pretrained(model_name)

text = "I love this movie"
tokens = tokenizer.tokenize(text)

#write the tokens to a tokens.csv file
with open("tokens.csv", "w") as f:
    for token in tokens:
        f.write(token + "\n")
        
