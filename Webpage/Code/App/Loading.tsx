import React from "react"

const Loading = () => (
    <div className="preloader-wrapper big active" style={{width: "100%"}}>
        <br />
        <br />
        
        <div className="spinner-layer spinner-blue">
            
            <div className="circle-clipper left">
                <div className="circle" />
            </div>

            <div className="gap-patch">
                <div className="circle" />
            </div>
            
            <div className="circle-clipper right">
                <div className="circle" />
            </div>

        </div>

        <br />
        <br />
    </div>
)

export default Loading