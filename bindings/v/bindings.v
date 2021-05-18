module v

#flag -I @VMODROOT/src
#flag @VMODROOT/src/parser.o

import x.json2
import os

fn C.tree_sitter_v() &C.TSLanguage

pub const language = unsafe { C.tree_sitter_v() }

// load_node_types reads the node-types.json file for static analysis.
pub fn load_node_types() ?[]json2.Any {
	contents := os.read_file(os.join_path(@VMODROOT, 'src', 'node-types.json')) ?
	list := json2.raw_decode(contents) ?
	return list.as_arr()
}