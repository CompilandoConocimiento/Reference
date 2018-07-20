/* ========= BASIC REACT THINGS ===============*/
import React from "react"

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
		Text: (
			<div style={{fontSize: "1.1rem"}}>
				The Sieve of Eratosthenes is a simple algorithm
				to find all the primes equal of smaller than n.
				
				It is given that \( n \leq 10^7 \).

				<br />
				<br />

				<h6><b>How it Works?</b></h6>
				<ol className="browser-default">
					<li>
						Suppose that all the numbers are prime
					</li>
					<li>
						\( 0, 1 \) are not prime
					</li>
					<li>
						For each number from \( 2 \) to \( n \) check if it is 
						prime:
						<ul className="browser-default">
							<li>
								If is prime: Delete all his multiples
							</li>
							<li>
								If is not prime: Don't do anything
							</li>
						</ul>
					</li>
				</ol>
				
				<h6><b>Optimizations</b></h6>

				One of the optimizations that we did here is that
				we avoid deleting many times the same numbers, for
				example the number \( 6 \) is going to be deleted
				by the \( 2 \) and the \( 3 \), so we start the multiples of \( i \)
				not in \( 2i \) but in \( i^2 \), because of this, we just need
				to check fewer numbers. 
			</div>
		),
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