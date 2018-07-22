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
		VisibleParts: [ [10, 23], [25, 45] ],
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
	},
	{
		Name: "Prime Factorization",
		Link: "Prime Factorization",
		File: "PrimeFactorization.cpp",
		VisibleParts: [ [17, 32], [36, 49] ],
		Size: 0.9,
		Text: (
			<div style={{fontSize: "1.1rem"}}>
				
				I asume that you know how to work with primes, if not
				check the Eratosthenes Sieve.

				The Prime Factorization algorithm presented here is just
				a simple modification of the Eratosthenes Sieve, so if you
				don't remember that Sieve, check it out.

				<br />
				<br />

				<h6><b>How it Works?</b></h6>
				<ol className="browser-default">
					<li>
						First, think of \( n \) into binary and check the number of \( 0's \),
						that are at end of \( n \), lets call them \( x \) and eliminate from the number.
						that means that the number can be divided by \( 2^x \) 

						For Example \( 10100 \rightarrow 101 \)
					</li>
					<li>
						After that \( n \) must be odd
					</li>
					<li>
						Use a kind of sieve to find how many time does it divided for each odd number,
						when you find a number that divide the new \( n \) divide the new \( n \) as many
						times as it can.
					</li>
				</ol>

				<br />
				<h6><b>Option B</b></h6>

				But, I you already have the vector of primes, don't complicate the things and just use
				the second code that I have give you.

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