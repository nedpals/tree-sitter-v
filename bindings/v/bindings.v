module v

#flag -I @VMODROOT/src
#flag @VMODROOT/src/parser.o

fn C.tree_sitter_v() &C.TSLanguage

pub const language = unsafe { C.tree_sitter_v() }