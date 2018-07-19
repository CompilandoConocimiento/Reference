
// =====================================================================
// ============               NUMBER THEORY        =====================
// =====================================================================
const NumberTheory = [
	{
		Name: "Sieve of Eratosthenes",
		Link: "SieveOfEratosthenes",
		File: "SieveOfEratosthenes.cpp",
		VisibleParts: [ [10, 45] ],
		Size: 1,
		Text: null,
	}
]


const Topics = [
	{
		Name: "Number Theory",
		Link: "NumberTheory",
		SubTopics: NumberTheory,
		BaseLink: "Code/NumberTheory/"
	},
]

export const Data = {
	Topics,
	MiniData: Topics.map(
		(Topic, ID) => [
			[Topic.Name, Topic.Link, ID],
			Topic.SubTopics.map ( (E, MiniID) => [E.Name, E.Link, MiniID]),
		]
	)
}