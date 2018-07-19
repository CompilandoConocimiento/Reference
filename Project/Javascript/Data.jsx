
// =====================================================================
// ============               NUMBER THEORY        =====================
// =====================================================================
const NumberTheory = [
	{
		Name: "Sieve of Eratosthenes",
		Link: "SieveOfEratosthenes.cpp",
		VisibleParts: [ [10, 45] ],
		Text: null,
	}
]


const Topics = [
	{
		Name: "Number Theory",
		SubTopics: NumberTheory,
		BaseLink: "Code/NumberTheory/"
	},
]

export const Data = {
	Topics,
	SideMenu: Topics.map(
		Topic => [Topic.Name, Topic.SubTopics.map (E => E.Name)]
	)
}