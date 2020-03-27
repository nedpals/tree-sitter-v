module main

type Expr = BinaryExpr | UnaryExpr | IfExpr 

struct Dog {}
struct Cat {}

const (
	pi    = 3.14
	world = '世界'
)

interface Speaker {
	speak() string
}

fn (d Dog) speak() string {
	return 'woof'
}

fn (c Cat) speak() string {
	return 'meow' 
}

fn perform(s Speaker) {
	println(s.speak())
}

fn main() {
    dog := Dog{}
    cat := Cat{}
    perform(dog) // "woof" 
    perform(cat) // "meow"
}