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
            {
            /*
            <div className="container">
                <div className="row">
                    <div className="col l6 s12">
                        <h5 className="white-text">About this</h5>
                        <p className="grey-text text-lighten-4">
                            This is 
                        </p>
                    </div>
                    <div className="col l4 offset-l2 s12">
                    </div>
                </div>
            </div>
            */
            }
            
            <br />
            <br />

            <div className="footer-copyright blue-grey darken-4">
                <div className="container">
                    Made by CompilandoConocimiento. Making the world a happier place
                </div>
            </div>
        </footer>
    )
}