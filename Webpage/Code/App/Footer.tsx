import React from "react"

const Footer: React.FunctionComponent = () => (
    <React.Fragment>
            <br />
            <br />
			<br />
			<br />
            <footer className="page-footer blue-grey darken-3">
                <div className="container white-text">
                    <div className="row">
                        <div className="col s6 m5 l4">
                            <h6>What is the Refence</h6>
                            <p style={{fontSize: "0.9em"}}>
                                The refence is a webapp/book that recopilate
                                all the algorithms that we have implemented 
                                for competitive programming.
                            </p>

                            <br />
                            <a 
                                href      = "https://compilandoconocimiento.github.io/Reference/Book/Reference.pdf" 
                                target    = "_blank" 
                                style     = {{padding: "0px 16px 0px 16px"}}
                                className = "btn-large btn-flat teal white-text">
                                Get the PDF
                            </a>
                        </div>
                        <div className="col m1 l4"/>
                        <div className="col s6 m5 l4">
                            <h6>Authors</h6>
                            <ul className="browser-default" style={{fontSize: "1.1rem", paddingInlineStart: "20px"}}>
                                <li>
                                    <a className="white-text" href="https://SoyOscarRH.github.io" target="_blank">
                                        <b>Soy</b>Oscar<b>RH</b>
                                    </a>
                                </li>
                                <li>
                                    <a className="white-text" href="https://github.com/alaneos777" target="_blank">
                                        <b>Alan </b>Ontiveros
                                    </a>
                                </li>
                            </ul>

                            <br />
                            <h6>Links</h6>
                            <ul className="browser-default" style={{fontSize: "1.1rem", paddingInlineStart: "20px"}}>
                                <li>
                                    <a className="white-text" href="https://github.com/CompilandoConocimiento" target="_blank">
                                        <b>Github</b>
                                    </a>
                                </li>
                            </ul>

                        </div>
                    </div>
                </div>

                <div className="footer-copyright blue-grey darken-4">
                    <div className="container">
                        Made by CompilandoConocimiento. 
                        Making the world a happier place
                    </div>
                </div>

                </footer>
    </React.Fragment>
)

export default Footer