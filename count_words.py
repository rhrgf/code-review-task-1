import nltk
import json
import os
import sys  


class Count_Words():
	def __init__(self, config_file = ""):
		self.config_file = config_file
		self.words_files = ['words.txt']
		self.load_config()

	def load_config(self):
		if os.path.exists(self.config_file) :
			with open (self.config_file) as f:
				self.config = json.loads(f.read())
		else :
			self.config = {}

		if 'words_files' in self.config:
			self.words_files = self.config['words_files']

	def count_words(self):
		for words_file in self.words_files :
			if os.path.exists(words_file) :
				with open (words_file) as f:
					text = f.read()
	#				words = nltk.tokenize.word_tokenize(text)
					words = []
					for line in text.split("\n"):
						words += line.split(" ")
					fredist = nltk.FreqDist(words)
					self.print_count(fredist)
			else :
				print("file " + words_file + " not exists.")

	def print_count(self, fredist):
		for k,v in fredist.most_common():
			print(str(k) + " " + str(v))
		print("")


if __name__ == '__main__':
	config_file = ""
	if len(sys.argv) >= 2:
		for i in range(1, len(sys.argv)):
			argv = sys.argv[i]
			if(argv[0:9] == "--config="):
				config_file = argv[9:]
	if config_file:
		cw = Count_Words(config_file = config_file)
	else :
		cw = Count_Words()

	cw.count_words()