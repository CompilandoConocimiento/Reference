import React from "react"

const Footer2: React.FunctionComponent = () => (
    <footer className="page-footer blue-grey darken-3">
        <div className="container" style={{fontSize: "0.8em"}}>
            <div className="row">
                <div className="col s6">
                    <h6 className="white-text">What is the Refence</h6>
                    <p className="white-text">
                        The refence is a webapp/book that recopilate
                        all the algorithms that we have implemented 
                        for competitive programming
                    </p>

                    <br />
                    <a 
                        href      = "https://compilandoconocimiento.github.io/Reference/Book/Reference.pdf" 
                        target    = "_blank" 
                        className = "waves-effect waves-light btn-large">
                        Get the PDF
                    </a>
                </div>
                <div className="col s6">
                    <h6 className="white-text">Authors</h6>
                    <ul className="browser-default" style={{fontSize: "1.1rem"}}>
                        <a href="https://SoyOscarRH.github.io" target="_blank">
                            <li className="white-text">
                                <b>Soy</b>Oscar<b>RH</b>
                            </li>
                        </a>
                        <a href="https://github.com/alaneos777" target="_blank">
                            <li className="white-text">
                                <b>Alan </b>Ontiveros
                            </li>
                        </a>
                    </ul>

                    <br />
                    <a href="https://github.com/CompilandoConocimiento" target="_blank">
                        <h6 className="white-text">Github</h6>
                    </a>

                    <a href="https://CompilandoConocimiento.com" target="_blank">
                        <h6 className="white-text">CompilandoConocimiento.com</h6>
                    </a>

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
)


const Footer: React.FunctionComponent = () => (
    <footer className="page-footer blue-grey darken-3">

        <div className="container white-text">
            <div className="row">
                <div className="col s6">
                    <h6>What is the Refence</h6>
                    <p style={{fontSize: "0.9em"}}>
                        The refence is a webapp/book that recopilate
                        all the algorithms that we have implemented 
                        for competitive programming
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
                <div className="col s6">
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
)

export default Footer