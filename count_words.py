import nltk
import json
import os
import sys  

class CountWords():

	def __init__(self, config_file = ""):
		self.config_file = config_file
		self.words_files = ["words.txt"]

	def load_config(self):
		'''load words files from config file if config file exists'''
		self.config = {}
		if os.path.exists(self.config_file) :
			with open (self.config_file) as f:
				self.config = json.loads(f.read())			

		if 'words_files' in self.config:
			self.words_files = self.config["words_files"]

		return self.words_files

	def read_file(self):
		'''read text from words files, save as list'''
		self.text = []
		for words_file in self.words_files :
			if os.path.exists(words_file) :
				with open (words_file) as f:
					self.text.append(f.read())
			else :
				print("file " + words_file + " not exists.")
		return self.text

	def count_words(self, text = None):
		'''count words from text'''
		if text == None :
			text = self.text
		words = []
		for t in text :
			words += t.split()
		self.fredist = nltk.FreqDist(words)
		return self.fredist

	def print_count(self, fredist = None):
		'''print words count from most frequently to least'''
		if fredist == None :
			fredist = self.fredist
		for k,v in fredist.most_common():
			print(str(k) + " " + str(v))


if __name__ == '__main__':
	config_file = ""
	if len(sys.argv) >= 2:
		for i in range(1, len(sys.argv)):
			argv = sys.argv[i]
			if(argv[0:9] == "--config="):
				config_file = argv[9:]

	if config_file:
		cw = CountWords(config_file = config_file)
	else :
		cw = CountWords()

	cw.load_config()
	cw.read_file()
	cw.count_words()
	cw.print_count()
	