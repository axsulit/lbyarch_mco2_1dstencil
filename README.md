# 1D Stencil Operation in C and x86-64 Assembly

The 1D Stencil Operation is illusrated as:
Y[i] = X[i] + X[i+1] + X[i+2] + X[i+3] + X[i+4] + X[i+5] + X[i+6] <br>

This was implemented in its C and x86-64 kernels.

### Average Execution Times

<table>
    <thead>
        <tr>
            <th>Layer 1</th>
            <th>Layer 2</th>
            <th>Layer 3</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=4>L1 Name</td>
            <td rowspan=2>L2 Name A</td>
            <td>L3 Name A</td>
        </tr>
        <tr>
            <td>L3 Name B</td>
        </tr>
        <tr>
            <td rowspan=2>L2 Name B</td>
            <td>L3 Name C</td>
        </tr>
        <tr>
            <td>L3 Name D</td>
        </tr>
    </tbody>
</table>