# SOTOSOPP 🍜🥣🐴
The goal of this project is to make an image processing application (filter) harnessing the power of parallel programming and GPU ⚡⚡ with CUDA 🐴🐴. You can use it by turning your camera on or just input an image to the GUI and select your desired filter. That's it :>. The GUI is very easy to operate and I don't even think you'll need a tutorial for it ~~please give me a good score, ngl im very tired~~

## Features
1. The users can choose to input an image manually or choose an image through the GUI.
2. The users can save the filter image as a .jpg file.
3. WE HAVE MANY FILTERSS. There's grayscale, editing the contrast and saturation, box filter, and a very cooolll edge detection.
## Requirements 
The GUI is built on top of Windows Forms so I'm sorry linux user, it's for windows only 😢.
### To Run the App
- Windows 10 or newer
- .Net Framework v4.7.2 or newer
- CUDA GPU with an architecture of `sm_52` and `compile_52` or newer

### To Edit the App
- All the above
- Common Language Runtime (CLR)
- OpenCV
- Visual Studio 2022
## How to Use
Open shell from the parent directory and execute the following command.

```sh
x64\Release\1-sotosop.exe
```
A window will pop up just like this:
![[How to use]](./assets/1.png)
If you wanted to try the filter from you camera, click the checkbox besides `Camera?`. If you wanted to try it from image, click the button with a text saying `choose_file`. Then, you can click which filter you wanted to try and click `Filter!`.
## Demo
Here are a couple screenshot of the program.
![[Demo 1]](./assets/2.png)
![[Demo 2]](./assets/3.png)
![[Demo 3]](./assets/4.png)
## Author
- Saddam Annais Shaquille 
- 13521121
## Project Status
The program is finished with all the bonus :>>>

| Poin  | Yes | No |
|---|---|---|
| Program can be compiled without error | ✓ |   |
| Program successfully run | ✓ |   |
| The program can read input / generate itself and provide output | ✓ |   |
| All the program is using GPU (CUDA) | ✓ |  |
| Grayscale | ✓ |  |
| Contrast | ✓ |  |
| Saturation | ✓ |  |
| Box Blur | ✓ |  |
| Sobel Edge Detection | ✓ |  |
| Live preview editing | ✓ |  |
| Live preview from camera | ✓ |  |