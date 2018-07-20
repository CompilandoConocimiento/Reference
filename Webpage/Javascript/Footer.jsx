// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"

// =====================================================================
// ============     HEADER COMPONENT       =============================
// =====================================================================
export default function Footer(props) {

    function DaysSince(Date1) {

        const SecondsInADay = 1000 * 60 * 60 * 24
    
        const Date1InMs = Date1.getTime()
        const Date2InMs = Date.now()

        const DifferenceMs = Math.abs(Date1InMs - Date2InMs)
    
        return Math.round(DifferenceMs / SecondsInADay)
    }

    return (
        <footer className="page-footer blue-grey darken-3">
            <div className="container">
                <div className="row">
                    <div className="col l6 s12">
                        <h6 className="white-text">What is the Refence</h6>
                        <p className="white-text">
                            The refence is a webapp/book that recopilate
                            all the algorithms that we have implemented 
                            for competitive programming
                        </p>

                        <br />
                        <a className="waves-effect waves-light btn-large">Get the PDF</a>
                    </div>
                    <div className="col l4 offset-l2 s12">
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
                    </div>
                </div>
            </div>
            
            <div className="footer-copyright blue-grey darken-4">
                <div className="container">
                    Made by CompilandoConocimiento. Making the world a happier place
                </div>
            </div>
        </footer>
    )
}