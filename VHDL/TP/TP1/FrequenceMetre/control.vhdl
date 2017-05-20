library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: control --

entity control is
  port ( clk : in STD_LOGIC;
         valid : out STD_LOGIC;
         raz : out STD_LOGIC;
         verr : out STD_LOGIC);
end control;

architecture behavioral of control is
    type etat_type is (zero,un,deux,trois,quatre,cinq);
    signal etat : etat_type := zero;
    signal etat_suiv : etat_type;
    signal count : STD_LOGIC_VECTOR(26 downto 0);

begin

SYNC : process(clk)
begin
    if rising_edge(clk) then
        etat <= etat_suiv;
        if etat = un then
            count <= count + 1;
        elsif etat=zero then
            count <= (others => '0');
        end if;
    end if;
end process;

COMB : process(etat,count)
begin
    case etat is
        when zero =>
            valid <= '0';
            raz <= '0';
            verr <= '0';
            etat_suiv <= un;
        when un =>
            valid <= '1';
            raz <= '0';
            verr <= '0';
            -- wait 1s : 100_000_000 clk_up 0x5F5E100 (27 bits)
            if count= X"5F5E100" then
                etat_suiv <= deux;
            else
                etat_suiv <= un;
            end if;
        when deux =>
            valid <= '0';
            raz <= '0';
            verr <= '0';
            etat_suiv <= trois;
        when trois =>
            valid <= '0';
            raz <= '1';
            verr <= '0';
            etat_suiv <= quatre;
        when quatre =>
            valid <= '0';
            raz <= '0';
            verr <= '0';
            etat_suiv <= cinq;
        when cinq =>
            valid <= '0';
            raz <= '0';
            verr <= '1';
            etat_suiv <= zero;
    end case;
end process;

end behavioral;
