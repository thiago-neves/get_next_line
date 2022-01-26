<h3 align="center">42 São Paulo</h3>
<div align="center">

![License](https://img.shields.io/github/license/thiago-neves/get_next_line)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952?color=white)
![Top language](https://img.shields.io/github/languages/top/thiago-neves/get_next_line?color=007FFF)

</div>

# 📑 get_next_line
A function that returns a line read from a file descriptor.

## 🏁 Getting Started

All you need to do is to add these c files to your project and run the get_next_line function, it can be used as a condition loop to loop trough all the file descriptor.<br>
Example:

```
char	*line;
int	file_descriptor;

folder = open(path, O_RDONLY);

while(get_next_line(file_descriptor, &line))
{
	// Do stuff
}
```
