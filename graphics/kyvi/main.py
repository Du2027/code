from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.image import Image
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.core.clipboard import Clipboard

import hashlib

algorythm = ""

class SayHello(App):
    def build(self):

        self.window = GridLayout()
        self.window.cols = 1
        self.window.size_hint = (0.6, 0.7)
        self.window.pos_hint = {"center_x": 0.5, "center_y": 0.5}

        self.select_l = Label(text="Select Algorythm", size_hint_y=0.5)
        self.Enter_str_l = Label(text="Enter String", size_hint_y=0.7)
        self.Enter_salt_l = Label(text="Enter Salt", size_hint_y=0.7)
        self.hash_input = TextInput(multiline=False, size_hint_y= 0.7)
        self.hash_button = Button(text="hash", size_hint_y=0.9)
        self.salt_input = TextInput(multiline=False, size_hint_y=0.5)
        self.button_sha512 = Button(text="512", size_hint_y = 0.3)
        self.button_sha256 = Button(text="256", size_hint_y = 0.3)
        
        self.hash_button.bind(on_press=lambda x:self.hash(algorythm, "a"))
        self.button_sha512.bind(on_press=self.sha512_pressed)
        self.button_sha256.bind(on_press=self.sha256_pressed)

        self.window.add_widget(Image(source="Hash-Logo.png"))
        self.window.add_widget(self.select_l)
        self.window.add_widget(self.button_sha512)
        self.window.add_widget(self.button_sha256)
        self.window.add_widget(self.Enter_str_l)
        self.window.add_widget(self.hash_input)
        self.window.add_widget(self.Enter_salt_l)
        self.window.add_widget(self.salt_input)
        self.window.add_widget(self.hash_button)

        return self.window
    
    def hash(self, algorythm, instance):
        if algorythm == "":
            print("fail")
            return -1

        input_str = self.hash_input.text
        salt = self.salt_input.text
        to_hash = input_str + salt
        to_hash = to_hash.encode('utf-8')

        if algorythm == "sha512":
            hashed = hashlib.sha512()

        elif algorythm == "sha256":
            hashed = hashlib.sha256()
        else:
            hashed = hashlib.sha512()

        hashed.update(to_hash)
        str_hash = hashed.hexdigest()

        self.select_l.text = "hash = " + str_hash
        Clipboard.copy(str_hash)
        
        #Load Second Site
        self.window.remove_widget(self.select_l)
        self.window.remove_widget(self.hash_input)
        self.window.remove_widget(self.hash_button)
        self.window.remove_widget(self.salt_input)
        self.window.remove_widget(self.Enter_str_l)
        self.window.remove_widget(self.Enter_salt_l)
        self.window.remove_widget(self.button_sha512)
        self.window.remove_widget(self.button_sha256)

        self.finished_l = Label(text="Finished Hashing")
        self.hash_l = Label(text=str_hash, font_size="10sp")

        if salt == "":
            self.process_l = Label(text="from: " + input_str +" algorythm = " + algorythm, size_hint_y = 0.2)
        else:
            self.process_l = Label(text ="from: "+ input_str + " with (salt): " + salt +" algorythm = " + algorythm, size_hint_y = 0.5)

        self.window.add_widget(self.finished_l)
        self.window.add_widget(self.process_l)
        self.window.add_widget(self.hash_l)

    def sha512_pressed(self, instance):
        global algorythm
        algorythm = "sha512"

    def sha256_pressed(self, instance):
        global algorythm
        algorythm = "sha256"
        print(algorythm)

if __name__ == "__main__":
    SayHello().run()
